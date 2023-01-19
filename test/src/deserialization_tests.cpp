#include <gtest/gtest.h>
#include <rapidcsv.h>

#include <sinks/test/test_sink.h>
#include <sinks/stdout/stdout_sink.h>
#include <sources/pcapng_source.h>

#include <cassert>
#include <fstream>
#include <iostream>
#include <string_view>

using case_string = std::array<std::string, 5>;

const std::string csv_path { "../cases/csv/" };
const std::string pcapng_path { "../cases/pcapng/" };

void check_file_path(std::string const& path)
{
    try {
        std::ifstream cases_file(path);
        EXPECT_TRUE(cases_file.good()) << "Can't open '" << path << "'";
    } catch (std::exception& ex) {
        FAIL() << path << " does not exits\n"
               << ex.what();
    }
};

std::vector<case_string> generate_args()
{
    const std::string cases_csv_path { "../cases/csv/cases.csv" };
    check_file_path(cases_csv_path);

    rapidcsv::Document csv_doc(cases_csv_path);

    std::vector<case_string> cases;
    for (int i = 0; i < csv_doc.GetRowCount(); i++) {
        auto case_row = csv_doc.GetRow<std::string>(i);
        case_string str;
        std::copy_n(case_row.begin(), 5, str.begin());
        cases.emplace_back(std::move(str));
    }

    return cases;
}

class deserialization_test : public testing::TestWithParam<case_string> {
public:
    static void SetUpTestCase() { }
};

TEST_P(deserialization_test, check_sigle_pcapng)
{
    // number | pcapng_file | layer_2_file | layer_3_file | layer_4_file
    auto case_row = GetParam();

    case_row[1] = pcapng_path + case_row[1];
    std::transform(
        case_row.cbegin() + 2,
        case_row.cend(),
        case_row.begin() + 2,
        [](std::string s) { return csv_path + s; });

    auto [str_number, pcapng_file, layer_2_file, layer_3_file, layer_4_file] = case_row;
    int packet_number = stoi(str_number);

    for (int idx : { 1, 2, 3, 4 }) {
        check_file_path(case_row[idx]);
    }

    auto source = std::make_unique<pcapng_source>(pcapng_file);
    auto sink = std::unique_ptr<test_sink>(new test_sink());
    auto print_sink = std::unique_ptr<stdout_sink>(new stdout_sink());

    source->add_sink(sink.get());
    //source->add_sink(print_sink.get());

    EXPECT_NO_THROW(source->run());
    EXPECT_GT(sink->packets().size(), 0) << "Could not parse single packet";

    // compare deserialized packet to csv field by field
    auto per_layer_compare = [packet_number](protocol_header const* const header,
                                 std::string csv_path) {
        auto read_row = [&csv_path, packet_number]() {
            try {
                return rapidcsv::Document(csv_path, rapidcsv::LabelParams(0, 0))
                    .GetRow<std::string>(std::to_string(packet_number));
            } catch (std::exception& ex) {
                std::cerr << "SKIPPING TEST FOR THIS LAYER | '" <<csv_path << "' packet number " << packet_number << " does not exist" << std::endl;
                return std::vector<std::string>();
            }
        };

        auto header_csv = read_row();
        if(header_csv.empty()){
            return;
        }

        EXPECT_EQ(header->field_count(), header_csv.size())
            << "Different number of fields";
        for (int i = 0; i < header->field_count(); i++) {
            EXPECT_EQ(header_csv[i], (*header)[i].first)
                << "FIELD '" << (*header)[i].second << "'";
        }
    };

    auto const& packet = sink->packets().back();
    for (auto&& [header, csv] :
        std::array<std::pair<protocol_header const* const, std::string>, 3> {
            { { packet.get_datalink().get(), layer_2_file },
                { packet.get_network().get(), layer_3_file },
                { packet.get_transport().get(), layer_4_file } } }) {
        per_layer_compare(header, csv);
    }
}

INSTANTIATE_TEST_SUITE_P(MyGroup,
    deserialization_test,
    testing::ValuesIn(generate_args()));

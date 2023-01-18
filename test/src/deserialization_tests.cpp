#include <gtest/gtest.h>
#include <rapidcsv.h>

#include <sinks/test/test_sink.h>
#include <sources/pcapng_source.h>

#include <cassert>
#include <fstream>
#include <iostream>
#include <string_view>

class deserialization_test : public ::testing::Test {
protected:
    const std::string cases_csv_path { "../cases/csv/cases.csv" };

    void SetUp()
    {
        try {
            std::ifstream cases_file(cases_csv_path);
            EXPECT_TRUE(cases_file.good()) << "Can't open '" << cases_csv_path << "'";
        } catch (std::exception& ex) {
            FAIL() << cases_csv_path << " does not exits\n"
                   << ex.what();
        }
    }
    void TearDown() { }
};

TEST_F(deserialization_test, test_1)
{
    rapidcsv::Document doc(cases_csv_path);
    std::cout << doc.GetRowCount() << std::endl;

    auto sink = std::unique_ptr<test_sink>(new test_sink());

    for (int i = 0; i < doc.GetRowCount(); i++) {
        auto row = doc.GetRow<std::string>(i);
        auto pcapng_path = row.at(1);

        EXPECT_TRUE(std::ifstream(pcapng_path).good());

        auto source = std::make_unique<pcapng_source>(pcapng_path);
        source->add_sink(sink.get());

        EXPECT_NO_THROW(source->run());
    }
}
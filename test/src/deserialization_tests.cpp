#include <gtest/gtest.h>

#include <sinks/stdout/stdout_sink.h>
#include <sources/pcapng_source.h>

#include <fstream>
#include <iostream>

#include <cassert>

class deserialization_test : public ::testing::Test {
    std::vector<std::string> _cases;
protected:
    void SetUp()
    {
        std::vector<std::string> files { "../pcapng/tcp_3_packages.pcapng" };
        for (const auto& file_name : files) {
            assert(std::ifstream(file_name).good());
        }
    }
    void TearDown() { }
};

TEST_F(deserialization_test, test_1)
{
    auto sink = std::unique_ptr<stdout_sink>(new stdout_sink());
    auto source = std::make_unique<pcapng_source>("../pcapng/tcp_3_packages.pcapng");
    source->add_sink(sink.get());

    try {
        source->run();
    } catch (source_exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}
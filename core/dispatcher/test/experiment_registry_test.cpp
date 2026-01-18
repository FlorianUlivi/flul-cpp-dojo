#include <sstream>
#include <string>

#include <experiment_registry.hpp>
#include <gtest/gtest.h>

namespace flul_cpp_dojo {
namespace {

class ExperimentRegistryTest : public ::testing::Test {
   protected:
    void SetUp() override {
        ExperimentRegistry::Instance().Clear();
    }

    void TearDown() override {
        ExperimentRegistry::Instance().Clear();
    }
};

TEST_F(ExperimentRegistryTest, SingletonReturnsSameInstance) {
    auto& instance1 = ExperimentRegistry::Instance();
    auto& instance2 = ExperimentRegistry::Instance();
    EXPECT_EQ(&instance1, &instance2);
}

TEST_F(ExperimentRegistryTest, RegisterSingleExperiment) {
    auto& registry = ExperimentRegistry::Instance();
    registry.RegisterExperiment("test", []() {});

    EXPECT_EQ(registry.Count(), 1);
    EXPECT_TRUE(registry.Contains("test"));
}

TEST_F(ExperimentRegistryTest, RegisterMultipleExperiments) {
    auto& registry = ExperimentRegistry::Instance();
    registry.RegisterExperiment("alpha", []() {});
    registry.RegisterExperiment("beta", []() {});
    registry.RegisterExperiment("gamma", []() {});

    EXPECT_EQ(registry.Count(), 3);
    EXPECT_TRUE(registry.Contains("alpha"));
    EXPECT_TRUE(registry.Contains("beta"));
    EXPECT_TRUE(registry.Contains("gamma"));
}

TEST_F(ExperimentRegistryTest, DuplicateNameLastWins) {
    auto& registry = ExperimentRegistry::Instance();
    int call_count = 0;

    registry.RegisterExperiment("dup", [&call_count]() { call_count = 1; });
    registry.RegisterExperiment("dup", [&call_count]() { call_count = 2; });

    EXPECT_EQ(registry.Count(), 1);

    registry.RunAll();
    EXPECT_EQ(call_count, 2);
}

TEST_F(ExperimentRegistryTest, ClearRemovesAllExperiments) {
    auto& registry = ExperimentRegistry::Instance();
    registry.RegisterExperiment("a", []() {});
    registry.RegisterExperiment("b", []() {});

    registry.Clear();

    EXPECT_EQ(registry.Count(), 0);
    EXPECT_FALSE(registry.Contains("a"));
    EXPECT_FALSE(registry.Contains("b"));
}

TEST_F(ExperimentRegistryTest, RunAllWithNoExperimentsDoesNotCrash) {
    auto& registry = ExperimentRegistry::Instance();
    EXPECT_NO_THROW(registry.RunAll());
}

TEST_F(ExperimentRegistryTest, RunAllExecutesInAlphabeticalOrder) {
    auto& registry = ExperimentRegistry::Instance();
    std::string execution_order;

    registry.RegisterExperiment("zebra", [&]() { execution_order += "Z"; });
    registry.RegisterExperiment("apple", [&]() { execution_order += "A"; });
    registry.RegisterExperiment("mango", [&]() { execution_order += "M"; });

    std::streambuf* old_cout = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    registry.RunAll();

    std::cout.rdbuf(old_cout);

    EXPECT_EQ(execution_order, "AMZ");
}

TEST_F(ExperimentRegistryTest, RunAllOutputFormat) {
    auto& registry = ExperimentRegistry::Instance();
    registry.RegisterExperiment("Test Experiment", []() { std::cout << "output line"; });

    std::streambuf* old_cout = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    registry.RunAll();

    std::cout.rdbuf(old_cout);

    std::string expected = "=== Test Experiment ===\noutput line\n";
    EXPECT_EQ(captured.str(), expected);
}

TEST_F(ExperimentRegistryTest, BuilderRegistersImmediatelyOnExecute) {
    auto& registry = ExperimentRegistry::Instance();

    EXPECT_FALSE(registry.Contains("immediate"));

    ExperimentRegistry::Builder("immediate").Execute([]() {});

    EXPECT_TRUE(registry.Contains("immediate"));
}

TEST_F(ExperimentRegistryTest, BuilderWithoutExecuteDoesNotRegister) {
    auto& registry = ExperimentRegistry::Instance();

    {
        ExperimentRegistry::Builder builder("no_execute");
        static_cast<void>(builder);
    }

    EXPECT_FALSE(registry.Contains("no_execute"));
    EXPECT_EQ(registry.Count(), 0);
}

}  // namespace
}  // namespace flul_cpp_dojo

#include <gtest/gtest.h>
#include "configlib/ConfigManager.hpp"
#include <fstream>

// Helper function to create a sample config file
void createSampleConfigFile(const std::string& filePath) {
    std::ofstream configFile(filePath);
    configFile << R"({
        "username": "test_user",
        "timeout": 60
    })";
    configFile.close();
}

// Unit test suite
class ConfigManagerTest : public ::testing::Test {
protected:
    const std::string configFilePath = "test_config.json";

    void SetUp() override {
        createSampleConfigFile(configFilePath);
    }

    void TearDown() override {
        std::remove(configFilePath.c_str());  // Clean up the test file
    }
};

TEST_F(ConfigManagerTest, LoadConfigSuccessfully) {
    configlib::ConfigManager configManager(configFilePath);
    EXPECT_NO_THROW(configManager.load());
}

TEST_F(ConfigManagerTest, GetExistingKey) {
    configlib::ConfigManager configManager(configFilePath);
    EXPECT_EQ(configManager.get<std::string>("username"), "test_user");
    EXPECT_EQ(configManager.get<int>("timeout"), 60);
}

TEST_F(ConfigManagerTest, SetAndSaveNewKey) {
    configlib::ConfigManager configManager(configFilePath);
    configManager.set("new_key", 42);
    configManager.save();

    configlib::ConfigManager newConfigManager(configFilePath);
    EXPECT_EQ(newConfigManager.get<int>("new_key"), 42);
}

TEST_F(ConfigManagerTest, ThrowWhenKeyNotFound) {
    configlib::ConfigManager configManager(configFilePath);
    EXPECT_THROW(configManager.get<int>("non_existent_key"), std::runtime_error);
}

TEST_F(ConfigManagerTest, SaveCreatesValidFile) {
    const std::string testFile = "output_test.json";
    configlib::ConfigManager configManager(testFile);
    configManager.set("test_key", "value");
    configManager.save();

    configlib::ConfigManager loadedConfig(testFile);
    EXPECT_EQ(loadedConfig.get<std::string>("test_key"), "value");

    std::remove(testFile.c_str());  // Clean up
}

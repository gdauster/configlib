#include "configlib/ConfigManager.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace configlib {

ConfigManager::ConfigManager(const std::string& configFilePath) : configFilePath_(configFilePath) {
    load();  // Load configuration on initialization
}

void ConfigManager::load() {
    std::ifstream configFile(configFilePath_);
    if (!configFile.is_open()) {
        throw std::runtime_error("Failed to open configuration file: " + configFilePath_);
    }

    try {
        configFile >> configData_;
    } catch (const nlohmann::json::parse_error& e) {
        throw std::runtime_error("Failed to parse configuration file: " + std::string(e.what()));
    }
}

void ConfigManager::save() const {
    std::ofstream configFile(configFilePath_);
    if (!configFile.is_open()) {
        throw std::runtime_error("Failed to open configuration file for writing: " + configFilePath_);
    }

    try {
        configFile << configData_.dump(4);  // Pretty-print with 4-space indentation
    } catch (const std::exception& e) {
        throw std::runtime_error("Failed to write to configuration file: " + std::string(e.what()));
    }
}

}  // namespace configlib

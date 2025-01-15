#include "configlib/ConfigManager.hpp"
#include <iostream>

int main() {
    configlib::ConfigManager config("config.json");

    // Set and get a configuration value
    config.set("username", "admin");
    config.set("timeout", 30);

    std::cout << "Username: " << config.get<std::string>("username") << std::endl;
    std::cout << "Timeout: " << config.get<int>("timeout") << std::endl;

    // Save to file
    config.save();

    return 0;
}

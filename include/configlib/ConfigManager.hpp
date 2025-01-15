#ifndef CONFIG_MANAGER_HPP
#define CONFIG_MANAGER_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace configlib {

class ConfigManager {
public:
    // Constructor to initialize with a configuration file path
    explicit ConfigManager(const std::string& configFilePath);

    // Load configuration from the file
    void load();

    // Save current configuration to the file
    void save() const;

    // Get a value of a specific key
    template<typename T>
    T get(const std::string& key) const {
        if (!keyExists(key)) {
            throw std::runtime_error("Key not found: " + key);
        }
        return configData_.at(key).get<T>();
    }

    // Set a value for a specific key
    template<typename T>
    void set(const std::string& key, const T& value) {
        configData_[key] = value;
    }
    
    // Helper function to check if a key exists
    bool keyExists(const std::string& key) const {
        return configData_.contains(key);
    }

private:
    std::string configFilePath_;    // Path to the configuration JSON file
    nlohmann::json configData_;     // Internal storage for configuration

};

} // namespace configlib

#endif // CONFIG_MANAGER_HPP

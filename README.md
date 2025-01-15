# configlib
 A modular configuration class

## Project Structure

config-lib/
│
├── CMakeLists.txt             # Root CMake configuration
├── include/                   # Public header files
│   └── configlib/             # Namespace folder
│       └── ConfigManager.hpp  # Public interface for configuration management
├── src/                       # Source files
│   ├── CMakeLists.txt         # CMake config for sources
│   └── ConfigManager.cpp      # Implementation file for ConfigManager
├── tests/                     # Unit tests for the library
│   ├── CMakeLists.txt         # CMake config for tests
│   └── test_config_manager.cpp # Unit test file
├── examples/                  # Example usage of the library
│   └── example_config.cpp     # Demonstration of the API
├── third_party/               # (Optional) External dependencies like JSON library
└── data/                      # Example or default JSON configuration files


## Build notes

1. CMake configuration:
Ensure CMAKE_INSTALL_PREFIX is correctly set to the MSYS2 environment (C:/msys64/mingw64).

Use the following command to build the project:

```
mingw32-make
```

## Tests tips

1.Add Google Test to your project or install it:

```
sudo apt-get install libgtest-dev
```

2.Update your tests/CMakeLists.txt to link with gtest and gtest_main:

```
find_package(GTest REQUIRED)
target_link_libraries(test_config_manager PRIVATE GTest::GTest GTest::Main nlohmann_json::nlohmann_json)

```
3.Run the tests:

```
ctest --output-on-failure
```

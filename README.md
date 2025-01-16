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


## CMake Build Instructions

### Linux

1. Ensure CMake and a C++ compiler (GCC or Clang) are installed:

        sudo apt-get install cmake g++ nlohmann-json3-dev

2. Create a build directory and compile:

        mkdir build && cd build
        cmake ..
        make

3. Run the tests:

        ctest --output-on-failure


### Windows (MSYS2)

1. Install MSYS2 and required packages:

        pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake mingw-w64-x86_64-make
        pacman -S mingw-w64-x86_64-nlohmann-json mingw-w64-x86_64-gtest

2. Open MSYS2 MinGW64 terminal and create a build directory:

        mkdir build && cd build
        cmake -G "MinGW Makefiles" ..
        mingw32-make

3. Run the tests:

        ctest --output-on-failure

### Windows (MSVC)

1. Install Visual Studio with C++ tools and CMake integration.

2. Open a Developer Command Prompt and configure the build:

        mkdir build && cd build
        cmake -G "Visual Studio 17 2022" ..
        cmake --build . --config Release

3. Optionally, build and run tests using ctest.
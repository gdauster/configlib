cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(ConfigLib VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for public headers
include_directories(include)

# Link nlohmann::json
find_package(nlohmann_json 3.2.0 REQUIRED)  # Ensure a compatible version

# Add the library target
add_library(ConfigLib STATIC
    src/ConfigManager.cpp
)

# Use nlohmann::json for parsing JSON files
target_link_libraries(ConfigLib PRIVATE nlohmann_json::nlohmann_json)


# Link libraries (update as needed)
target_include_directories(ConfigLib PUBLIC include)
target_compile_features(ConfigLib PUBLIC cxx_std_17)

# Unit tests
enable_testing()
add_subdirectory(tests)

# Optionally build examples
option(BUILD_EXAMPLES "Build example programs" ON)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

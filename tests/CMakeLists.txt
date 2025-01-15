add_executable(test_config_manager test_config_manager.cpp)
target_link_libraries(test_config_manager PRIVATE ConfigLib)


find_package(GTest REQUIRED)
target_link_libraries(test_config_manager PRIVATE GTest::GTest GTest::Main nlohmann_json::nlohmann_json)

# Add a basic test
add_test(NAME ConfigManagerTest COMMAND test_config_manager)

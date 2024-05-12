find_package(doctest REQUIRED)

add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex doctest::doctest)

add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational rational doctest::doctest)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_complex)
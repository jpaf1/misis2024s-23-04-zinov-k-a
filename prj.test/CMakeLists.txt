find_package(doctest REQUIRED)

add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex doctest::doctest)

add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational rational doctest::doctest)

add_executable(test_dynarr test_dynarr.cpp)
target_link_libraries(test_dynarr dynarr doctest::doctest)

add_executable(test_stackarr test_stackarr.cpp)
target_link_libraries(test_stackarr stackarr doctest::doctest)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_complex)
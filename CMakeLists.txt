cmake_minimum_required(VERSION 3.10)

set(PROJECT_REVISION 1 CACHE INTERNAL "Project revision (CI)")
project(otus_cpp2
    VERSION 1.0.${PROJECT_REVISION}
    DESCRIPTION "Otus Cpp Course hwork 2"
    HOMEPAGE_URL "https://github.com/CityAplons/otus-cpp-02"
    LANGUAGES CXX
)

set_property(GLOBAL PROPERTY G_CXX_STANDARD 14)
set_property(GLOBAL PROPERTY G_CXX_STANDARD_REQUIRED ON)

# Include utility functions
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GNUInstallDirs)
include(compiler)
include(test)

# Transparent versioning
include_directories(cmake/version)
configure_file(cmake/version/version.h.in version.h)
configure_file(cmake/version/VERSION.in VERSION)
add_library(version cmake/version/project.cpp)
target_include_directories(version
    PRIVATE "${CMAKE_BINARY_DIR}"
)

# Describe build targets
include_directories(include/)
add_executable(ip_filter src/ip_filter.cpp)
add_library(ip_filter_solution
    src/io.cpp
    src/sort.cpp
    src/filter.cpp
)
target_link_libraries(ip_filter PRIVATE
    version
    ip_filter_solution
)

set_compile_options(ip_filter_solution)
set_compile_options(ip_filter)
set_compile_options(version)

install(TARGETS ip_filter
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(FILES ip_filter.tsv DESTINATION ${CMAKE_INSTALL_BINDIR})

# Describe unit tests
enable_testing()
add_unit_test(test/test_custom_tie.cpp "") # training task
add_unit_test(test/test_filter.cpp ip_filter_solution)
add_unit_test(test/test_sort.cpp ip_filter_solution)

# Packaging
option(MAKE_PACKAGE "Add 'package' and 'package_source' build targets for packages" ON)

if(MAKE_PACKAGE)
    add_subdirectory(cmake/packaging)
endif()
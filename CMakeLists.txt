cmake_minimum_required(VERSION 3.10)

set(PROJECT_REVISION 1 CACHE INTERNAL "Project revision (CI)")
project(otus_cpp2
    VERSION 0.0.${PROJECT_REVISION}
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
add_executable(hw2 src/ip_filter.cpp)
target_link_libraries(hw2 PRIVATE
    version
)

set_compile_options(hw2)
set_compile_options(version)

install(TARGETS hw2
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Describe unit tests
enable_testing()
add_unit_test(test/test_custom_tie.cpp "") # training task

# Packaging
option(MAKE_PACKAGE "Add 'package' and 'package_source' build targets for packages" ON)
if (MAKE_PACKAGE)
	add_subdirectory(cmake/packaging)
endif()
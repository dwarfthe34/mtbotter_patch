cmake_minimum_required(VERSION 2.6)

# Make sure CMP0079 is set to NEW
if(POLICY CMP0079)
    cmake_policy(SET CMP0079 NEW)
endif()

project(mtbotter)
set(PROJECT_NAME_CAPITALIZED "MtBotter")

# =====================
# Compiler
# =====================
set(CMAKE_CXX_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# =====================
# Version
# =====================
set(VERSION_MAJOR 5)
set(VERSION_MINOR 3)
set(VERSION_PATCH 0)
set(VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

message(STATUS "*** Building mtbotter ${VERSION_STRING} ***")

# =====================
# Options
# =====================
set(BUILD_CLIENT TRUE CACHE BOOL "Build client")
set(BUILD_SERVER FALSE CACHE BOOL "Build server")
set(BUILD_UNITTESTS TRUE CACHE BOOL "Build unittests")

# =====================
# Module path
# =====================
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

# =====================
# System deps
# =====================
find_package(GMP REQUIRED)
find_package(Json REQUIRED)
find_package(Lua REQUIRED)

# =====================
# Install paths (Linux)
# =====================
if(UNIX AND NOT APPLE)
    set(BINDIR "bin")
    set(SHAREDIR "share/${PROJECT_NAME}")
    set(DOCDIR "share/doc/${PROJECT_NAME}")
    set(LOCALEDIR "share/locale")
endif()

# =====================
# Sources
# =====================
add_subdirectory(src)

# =====================
# Link
# =====================
set_target_properties(mtbotter PROPERTIES POSITION_INDEPENDENT_CODE ON)
# No irrlicht linked anymore

# =====================
# Install
# =====================
install(FILES README.md DESTINATION ${DOCDIR})
install(FILES minetest.conf.example DESTINATION ${SHAREDIR})

install(DIRECTORY builtin DESTINATION ${SHAREDIR})
install(DIRECTORY games/minetest_game DESTINATION ${SHAREDIR}/games)
install(DIRECTORY games/devtest DESTINATION ${SHAREDIR}/games)

if(BUILD_CLIENT)
    install(DIRECTORY client/shaders DESTINATION ${SHAREDIR}/client)
    install(DIRECTORY textures/base/pack DESTINATION ${SHAREDIR}/textures/base)
    install(DIRECTORY fonts DESTINATION ${SHAREDIR})
endif()

# =====================
# Packaging
# =====================
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${VERSION_STRING})
set(CPACK_GENERATOR TGZ)
include(CPack)


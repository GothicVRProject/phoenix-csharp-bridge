cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(phoenix-csharp-bridge VERSION 0.1.0)


# WARNING: Changed file count isn't recognized by default
# If you add/remove a file, then you need to either change this CMakeLists.txt somewhere else as well
# or re-execute build directory creation
file(GLOB_RECURSE SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*")


##
# Phoenix project pre-setup
###
option(PHOENIX_BUILD_TESTS OFF)
option(PHOENIX_BUILD_EXAMPLES OFF)
option(PHOENIX_BUILD_TOOLS OFF)
add_subdirectory(dependencies/phoenix) # Add phoenix source folder to build process (Creating .a file)


add_library(phoenix-csharp-bridge SHARED ${SRC})

# uncomment for quick tests within main() function
#add_executable(phoenix-csharp-bridge ${SRC})

target_include_directories(phoenix-csharp-bridge PRIVATE src/include/)

# We need to "bake" standard C/C++ libraries into exe/DLL
# Otherwise we need to distribute libstdc++-6.dll into the same folder.
# If we don't do any of this, we'll get the following error:
# -> The procedure entry point _ZNKSt7codecvtlwc9_MbstatetE10do_unshiftERS0_PcS3_RS3_ could not be located in the dynamic link library [...]\build\test_lib.exe
target_link_options(phoenix-csharp-bridge PUBLIC "-static-libstdc++")


##
# Phoenix project post-setup
##
target_link_libraries(phoenix-csharp-bridge phoenix)

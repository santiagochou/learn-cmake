# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)  # 01-A

# Set the project name
# project (hello_cmake) # 01-A
# project(hello_headers) # 01-B
# project(hello_library) # 01-C
project(cmake_examples_install) #01-E


# 01-B: added by Santiago
set(CMAKE_C_COMPILER "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Tools\\MSVC\\14.27.29110\\bin\\Hostx64\\x64\\cl.exe")
set(CMAKE_CXX_COMPILER "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Tools\\MSVC\\14.27.29110\\bin\\Hostx64\\x64\\cl.exe")

#01-D: Santiago Add. for Windows need the *.lib for all of *.dll. solution from https://stackoverflow.com/questions/40739061/error-lnk1104-cannot-open-file-debug-myprojectlib-lib
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#01-F : Set build type.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message("Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# 01-G: Set Default C++ Flags
# Similarly to CMAKE_CXX_FLAGS other options include:
#     Setting C compiler flags using CMAKE_C_FLAGS
#     Setting linker flags using CMAKE_LINKER_FLAGS.
# the target_compile_definitions function is preferred.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compiler Flags" FORCE)

# Create a sources variable with a link to all cpp files to compile
# set(SOURCES   # 01-B
#     src/Hello.cpp 
#     src/main.cpp 
# )
# An alternative to setting specific file names in the SOURCES variable is to use a GLOB command to find files using wildcard pattern matching.
# file(GLOB SOURCES "src/*.cpp") # 01-B

# Generate the static library from the library sources
# add_library(hello_library STATIC #01-C
#     src/Hello.cpp
# )
# add_library(hello_library SHARED #01-D
#     src/Hello.cpp 
# )
add_library(cmake_examples_inst SHARED #01-E
    src/Hello.cpp 
)

# add_library(hello::library ALIAS hello_library) #01-D




# Add an executable
# add_executable(hello_cmake main.cpp) #01-A
# add_executable(${PROJECT_NAME} ${SOURCES}) #01-B
# add_executable(hello_binary #01-C
#     src/main.cpp
# )
add_executable(cmake_examples_inst_bin #01-E
    src/main.cpp 
)

# Link the new hello_library target with the hello_binary target
# target_link_libraries(hello_binary #01-C
#     PRIVATE 
#         hello_library
# )
# target_link_libraries(hello_binary #01-D
#     PRIVATE 
#         hello::library
# )
target_link_libraries(cmake_examples_inst_bin #01-E
    PRIVATE 
        cmake_examples_inst 
)   


# 01-B: Santiago --- target_include_directories() should be put on behind of the add_executable() -- maybe
# When you have different include folders, you can make your compiler aware of them using the target_include_directories() function. When compiling this target this will add these directories to the compiler with the -I flag e.g. -I/directory/path
# target_include_directories(hello_headers # 01-B
#     PRIVATE 
#         ${PROJECT_SOURCE_DIR}/include
# )
# target_include_directories(hello_library # 01-C
#     PUBLIC 
#         ${PROJECT_SOURCE_DIR}/include
# )
target_include_directories(cmake_examples_inst  #01-E
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


# 01-G : Set Per-Target C++ Flags, This will cause the compiler to add the definition -DEX3 when compiling the target.
# this function may need write in lower postion of CMakeLists.txt
target_compile_definitions(cmake_examples_inst
    PRIVATE EX3)

# Binaries
install(TARGETS cmake_examples_inst_bin #01-E
    DESTINATION bin)

# 01-E
# Library
# Note: may not work on windows
# install (TARGETS cmake_examples_inst
#     LIBRARY DESTINATION lib)

# Library -- Windows
install (TARGETS cmake_examples_inst # 01-E for windows
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ #01-E
    DESTINATION include)

# Config
install(FILES cmake-examples.conf #01-E
    DESTINATION etc)
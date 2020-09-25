cmake_minimum_required(VERSION 3.5)

#Set the project name
project(protobuf_example)

# Santiago Add.
# offer path to find_package().
set(CMAKE_MODULE_PATH"C:\\Playground\\Softwares\\protobuf\\protobuf_20200925\\install_debug\\cmake;${CMAKE_MODULE_PATH}")

# Santiago Add. For we use the libprotobuf_*.lib library.
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

#find the protobuf compiler and libraries
find_package(Protobuf REQUIRED)

# Santiago change from "PROTOBUF_FOUND" to "Protobuf_FOUND"
#check if protobuf was found, the "Protobuf" from "Protobuf_FOUND" are case-sensitive.
if(Protobuf_FOUND)
    message("protobuf found")
else()
    message(FATAL_ERROR "Cannot find Protobuf")
endif()

# generate the .h and .cxx files
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS AddressBook.proto)

# Print path to generated files
message("PROTO_SRCS = ${PROTO_SRCS}")
message("PROTO_HDRS = ${PROTO_HDRS}")

# Add an executable
# Santiago Commit: Default is console application, add WIN32 is for Windows application, its entry point
# is not main() function.
add_executable(protobuf_example
    main.cpp  
    ${PROTO_SRCS}
    ${PROTO_HDRS}
)

target_include_directories(protobuf_example
    PUBLIC
    ${Protobuf_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

# link the exe against the libraries
target_link_libraries(protobuf_example
    PUBLIC 
    ${Protobuf_LIBRARIES}
)
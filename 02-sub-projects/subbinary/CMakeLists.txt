project(subbinary)

#Create the excutable
add_executable(${PROJECT_NAME} main.cpp)

# Link libs
target_link_libraries(${PROJECT_NAME}
    sub::lib1
    sub::lib2
)
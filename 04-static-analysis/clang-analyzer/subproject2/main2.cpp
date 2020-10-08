#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    std::cout << "Hello Main2!" << std::endl;
    int* x;
    *x=4;
    std::cout<< x <<std::endl;

    int y[5];
    y[10]=0;

    return 0;
}
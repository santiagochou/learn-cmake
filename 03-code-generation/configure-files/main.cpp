#include <iostream>
#include "ver.h"  // We wanna generate it.
#include "path.h" // We wanna generate it.

int main(int argc, char *argv[])
{
    std::cout << "Hello version " << ver << "!" << std::endl;
    std::cout << "Path is " << path << std::endl;
    return 0;
}
rem this is just for record
scan-build.bat --use-analyzer C:\Playground\Softwares\llvm-project\build\Release\bin\clang++.exe -o temp cmake -G "MinGW Makefiles" -D CMAKE_C_COMPILER="C:/Strawberry/c/bin/gcc.exe" -D CMAKE_CXX_COMPILER="C:/Strawberry/c/bin/g++.exe" ..
scan-build.bat --use-analyzer C:\Playground\Softwares\llvm-project\build\Release\bin\clang++.exe -o temp make 
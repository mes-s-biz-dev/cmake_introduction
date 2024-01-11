cmake -S . -B build -DCMAKE_C_COMPILER=bcc32c -DCMAKE_CXX_COMPILER=bcc32c -G Ninja
cmake --build build

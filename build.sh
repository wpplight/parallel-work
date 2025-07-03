cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
# 使用四核心编译
make -j4

./main
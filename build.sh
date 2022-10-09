export LUA_PATH="$PWD/assets/scripts/?.lua;;"
clear
mkdir -p build
cd build
cmake ..
make
./test

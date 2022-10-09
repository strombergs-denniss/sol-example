#include <iostream>
#include <filesystem>
#include <sol/sol.hpp>

namespace fs = std::filesystem;

static sol::state lua;

int main() {
    lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math);
    lua.script_file("../assets/scripts/main.lua");

    return 0;
}

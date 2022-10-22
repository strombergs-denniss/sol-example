#include <iostream>
#include "state.hpp"
#include "entt_bind.hpp"
#include "glm_bind.hpp"

int main() {
    State state;
    state.lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math);
    bindEntt(state.lua, state.registry);
    bindGlm(state.lua);
    state.lua.script_file("../assets/scripts/main.lua");

    return 0;
}

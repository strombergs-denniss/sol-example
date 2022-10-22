#pragma once
#include <sol/sol.hpp>
#include <entt/entt.hpp>

struct State {
    sol::state lua;
    entt::registry registry;
};

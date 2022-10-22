#pragma once
#include <sol/sol.hpp>
#include <entt/entt.hpp>
#include "components/transform.hpp"

void bindEntt(sol::state& lua, entt::registry& registry);

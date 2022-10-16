#include <iostream>
#include <sol/sol.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

static sol::state lua;

int main() {
    lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math);

    sol::usertype<glm::vec3> vec3Type = lua.new_usertype<glm::vec3>(
        "vec3",
        sol::constructors<glm::vec3(float, float, float)>(),
        sol::meta_function::addition, sol::overload(
            [](const glm::vec3& a, const glm::vec3& b) -> glm::vec3 { return a + b; },
            [](const glm::vec3& a, const float b) -> glm::vec3 { return a + b; },
            [](const float a, const glm::vec3& b) -> glm::vec3 { return a + b; }
        ),
        sol::meta_function::subtraction, sol::overload(
            [](const glm::vec3& a, const glm::vec3& b) -> glm::vec3 { return a - b; },
            [](const glm::vec3& a, const float b) -> glm::vec3 { return a - b; },
            [](const float a, const glm::vec3& b) -> glm::vec3 { return a - b; }
        ),
        sol::meta_function::multiplication, sol::overload(
            [](const glm::vec3& a, const glm::vec3& b) -> glm::vec3 { return a * b; },
            [](const glm::vec3& a, const float b) -> glm::vec3 { return a * b; },
            [](const float a, const glm::vec3& b) -> glm::vec3 { return a * b; }
        ),
        sol::meta_function::division, sol::overload(
            [](const glm::vec3& a, const glm::vec3& b) -> glm::vec3 { return a / b; },
            [](const glm::vec3& a, const float b) -> glm::vec3 { return a / b; },
            [](const float a, const glm::vec3& b) -> glm::vec3 { return a / b; }
        )
    );
    vec3Type["x"] = &glm::vec3::x;
    vec3Type["y"] = &glm::vec3::y;
    vec3Type["z"] = &glm::vec3::z;

    sol::usertype<glm::vec4> vec4Type = lua.new_usertype<glm::vec4>(
        "vec4",
        sol::constructors<glm::vec4(float, float, float, float)>(),
        sol::meta_function::addition, sol::overload(
            [](const glm::vec4& a, const glm::vec4& b) -> glm::vec4 { return a + b; },
            [](const glm::vec4& a, const float b) -> glm::vec4 { return a + b; },
            [](const float a, const glm::vec4& b) -> glm::vec4 { return a + b; }
        ),
        sol::meta_function::subtraction, sol::overload(
            [](const glm::vec4& a, const glm::vec4& b) -> glm::vec4 { return a - b; },
            [](const glm::vec4& a, const float b) -> glm::vec4 { return a - b; },
            [](const float a, const glm::vec4& b) -> glm::vec4 { return a - b; }
        ),
        sol::meta_function::multiplication, sol::overload(
            [](const glm::vec4& a, const glm::vec4& b) -> glm::vec4 { return a * b; },
            [](const glm::vec4& a, const float b) -> glm::vec4 { return a * b; },
            [](const float a, const glm::vec4& b) -> glm::vec4 { return a * b; }
        ),
        sol::meta_function::division, sol::overload(
            [](const glm::vec4& a, const glm::vec4& b) -> glm::vec4 { return a / b; },
            [](const glm::vec4& a, const float b) -> glm::vec4 { return a / b; },
            [](const float a, const glm::vec4& b) -> glm::vec4 { return a / b; }
        )
    );
    vec4Type["x"] = &glm::vec4::x;
    vec4Type["y"] = &glm::vec4::y;
    vec4Type["z"] = &glm::vec4::z;
    vec4Type["w"] = &glm::vec4::w;

    sol::usertype<glm::mat4> mat4Type = lua.new_usertype<glm::mat4>(
        "mat4",
        sol::constructors<glm::mat4(float)>(),
        sol::meta_function::addition, sol::overload(
            [](const glm::mat4& a, const glm::mat4& b) -> glm::mat4 { return a + b; }
        ),
        sol::meta_function::subtraction, sol::overload(
            [](const glm::mat4& a, const glm::mat4& b) -> glm::mat4 { return a - b; }
        ),
        sol::meta_function::multiplication, sol::overload(
            [](const glm::mat4& a, const glm::mat4& b) -> glm::mat4 { return a * b; }
        ),
        sol::meta_function::division, sol::overload(
            [](const glm::mat4& a, const glm::mat4& b) -> glm::mat4 { return a / b; }
        )
    );

    lua["normalize"] = sol::overload(
        [](const glm::vec3& a) -> glm::vec3 { return glm::normalize(a); },
        [](const glm::vec4& a) -> glm::vec4 { return glm::normalize(a); }
    );

    lua["length"] = sol::overload(
        [](const glm::vec3& a) -> float { return glm::length(a); },
        [](const glm::vec4& a) -> float { return glm::length(a); }
    );

    lua["dot"] = sol::overload(
        [](const glm::vec3& a, const glm::vec3& b) -> float { return glm::dot(a, b); },
        [](const glm::vec4& a, const glm::vec4& b) -> float { return glm::dot(a, b); }
    );

    lua["cross"] = [](const glm::vec3& a, const glm::vec3& b) -> glm::vec3 { return glm::cross(a, b); };

    lua["translate"] = [](const glm::mat4& a, const glm::vec3& b) -> glm::mat4 { return glm::translate(a, b); };

    lua["scale"] = [](const glm::mat4& a, const glm::vec3& b) -> glm::mat4 { return glm::scale(a, b); };

    lua["rotate"] = [](const glm::mat4& a, float b, const glm::vec3& c) -> glm::mat4 { return glm::rotate(a, b, c); };

    lua["perspective"] = [](const float a, float b, float c, float d) -> glm::mat4 { return glm::perspective(a, b, c, d); };

    lua["lookAt"] = [](const glm::vec3& a, const glm::vec3& b, const glm::vec3& c) -> glm::mat4 { return glm::lookAt(a, b, c); };

    lua.script_file("../assets/scripts/main.lua");

    return 0;
}

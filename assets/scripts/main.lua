local module = require("module")
module.test()

local positionA = vec3.new(1, 2, 3)
local positionB = vec3.new(4, 5, 6)
print(positionA + positionB)
print(positionA - positionB)
print(positionA * positionB)
print(positionA / positionB)

local model = mat4.new(1.0)
print(model)
print(translate(model, positionA))

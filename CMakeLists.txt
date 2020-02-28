# cmake_minimum_required(VERSION <specify CMake version here>)
project(ReactorCppTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(ReactorCppTest main.cpp util/Clock.cpp util/Clock.h math/vec2.h actors/NeutronField.cpp actors/NeutronField.h actors/Neutron.h actors/Neutron.cpp util/Timer.cpp util/Timer.h math/Area2d.cpp math/Area2d.h actors/Moderator.cpp actors/Moderator.h godot/Node.h actors/NeutronRegion.h util/Utils.h util/Utils.cpp actors/NeutronRegion.cpp godot/Node.cpp)

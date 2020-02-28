# cmake_minimum_required(VERSION <specify CMake version here>)
project(ReactorCppTest)

set(CMAKE_CXX_STANDARD 17)

add_executable(ReactorCppTest main.cpp Clock.cpp Clock.h vec2.h NeutronField.cpp NeutronField.h Neutron.h Neutron.cpp Timer.cpp Timer.h Area2d.cpp Area2d.h Moderator.cpp Moderator.h Node.h NeutronRegion.h)

cmake_minimum_required(VERSION 3.20)
project(SquidGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(SquidGame main.cpp Users.cpp Users.h Contenders.cpp Contenders.h Supervisors.cpp Supervisors.h Game.h RedLightGreenLight.cpp RedLightGreenLight.h TugOfWar.cpp TugOfWar.h Marbles.cpp Marbles.h Genken.cpp Genken.h Prize.cpp Prize.h)

cmake_minimum_required(VERSION 3.25)
project(Tank_game)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5.1 COMPONENTS graphics audio)
add_executable(Tank_game main.cpp boom.cpp bullet.cpp check_collision.cpp items.cpp MusicEffect.cpp player.cpp)
target_link_libraries( Tank_game sfml-graphics sfml-audio)

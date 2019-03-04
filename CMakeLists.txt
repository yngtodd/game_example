cmake_minimum_required(VERSION 3.5)

project(mygame)

find_package(Torch REQUIRED)

include_directories("${TORCH_INCLUDE}")

# enables cmake testing
enable_testing()

add_subdirectory(game)
add_subdirectory(engine)

#add_library(application STATIC runner/application.cpp)
add_executable(app runner/application.cpp)
target_link_libraries(app game_lib engine_lib "${TORCH_LIBRARIES}")

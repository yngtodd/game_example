cmake_minimum_required(VERSION 3.5)


project(game)

# Create the main executable
# add the header files also so that the IDE knows they exist
# in the source tree
add_library(game_lib
	include/game.hpp
	src/game.cpp
	)

# add the include dir as a public include directory
# will be inherited by dependent targets
target_include_directories(game_lib PUBLIC include)
# add the include directory src which will only be visible by
# sample_exe
target_include_directories(game_lib PRIVATE src)

 if(BUILD_SHARED_LIBS)
     target_compile_definitions(game_lib PRIVATE GAME_EXPORTS)
     target_compile_definitions(game_lib INTERFACE GAME_IMPORTS)
endif()


## create test for greeter
#add_executable(greeter_test
#	tests/greeter_test.cpp
#)

#target_link_libraries(greeter_test	greeter_lib)

#add_test(greeter_test greeter_test)

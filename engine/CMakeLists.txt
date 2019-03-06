cmake_minimum_required(VERSION 3.5)


project(engine)

# Create the main executable
# add the header files also so that the IDE knows they exist
# in the source tree
add_library(engine_lib
	include/engine.hpp
	src/engine.cpp
	)

# add the include dir as a public include directory
# will be inherited by dependent targets
target_include_directories(engine_lib PUBLIC include)
# add the include directory src which will only be visible by
# sample_exe
target_include_directories(engine_lib PRIVATE src)
target_link_libraries(engine_lib)
set_property(TARGET engine_lib PROPERTY CXX_STANDARD 11)

 if(BUILD_SHARED_LIBS)
	 target_compile_definitions(engine_lib PRIVATE ENGINE_EXPORTS)
	 target_compile_definitions(engine_lib INTERFACE ENGINE_IMPORTS)
endif()


## create test for greeter
#add_executable(greeter_test
#	tests/greeter_test.cpp
#)

#target_link_libraries(greeter_test	greeter_lib)

#add_test(greeter_test greeter_test)

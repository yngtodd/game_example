cmake_minimum_required(VERSION 3.5)

project(engine)

## Building
# create fareweller library
add_library(engine_lib
    include/engine/config.h
	include/engine/engine.hpp
 	src/engine.cpp
 )

# setup include directories
target_include_directories(engine_lib PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
 	$<INSTALL_INTERFACE:include>
)
# setup export preprocessor definitions
if(BUILD_SHARED_LIBS)
    target_compile_definitions(engine_lib PRIVATE ENGINE_EXPORTS)
    target_compile_definitions(engine_lib INTERFACE ENGINE_IMPORTS)
endif()

## Testing
#add_executable(fareweller_test 	tests/fareweller_test.cpp)
#target_link_libraries(fareweller_test fareweller_lib)
#add_test(fareweller_test fareweller_test)
target_link_libraries(engine_lib)


## Installing
# add installation for target farweller

install(TARGETS engine_lib EXPORT engine_export
		RUNTIME DESTINATION bin
		ARCHIVE DESTINATION lib
		LIBRARY DESTINATION lib
		INCLUDES DESTINATION include
)
# copy public include files
install(FILES
    include/config.h
	include/engine.hpp
	DESTINATION include)


# create export file which can be imported by other cmake projects
install(EXPORT engine_export
	NAMESPACE sample::
	DESTINATION lib/cmake/engine_lib
)


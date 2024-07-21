cmake_minimum_required(VERSION 3.12)

project(static_library)

add_subdirectory(HelpingFunctionLibrary)

add_executable(
	Main
	Main.cpp
)
set_target_properties(Main PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_include_directories(
	Main
	PRIVATE
	${CMAKE_SOURCE_DIR}/HelpingFunctionLibrary
)
target_link_libraries(
	Main
	PRIVATE
	HelpingFunctionLibrary
)

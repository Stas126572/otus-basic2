cmake_minimum_required(VERSION 3.12)

project(HelpingFunctionLibrary)

add_library(
	HelpingFunctionLibrary
	STATIC
	check_value.cpp
	check_value.h
	high_scores.cpp
	high_scores.h
	random_value.cpp
	random_value.h
)

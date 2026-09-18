cmake_minimum_required(VERSION 3.10)
project(MyMultiFolderProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CAMKE_CXX_STANDARD_REQUIRED ON)

include_directories(
	Member1_Domain/include
	Member2_Domain/include
	Member3_Domain/include
)

file(GLOB_RECURSE SOURCES
	"main.cpp"
	"Member1_Domain/src/*.cpp"
	"Member2_Domain/src/*.cpp"
	"Member3_Domain/src/*.cpp"
)

add_executable(attendance_app ${SOURCES})
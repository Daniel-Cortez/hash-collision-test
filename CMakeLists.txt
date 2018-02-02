cmake_minimum_required(VERSION 2.6)
set(PROJECT_NAME "TestApp")

project(${PROJECT_NAME} CXX)
set(APP_SRC
	functions/MurmurHash2.h
	functions/MurmurHash2.cpp
	functions/MurmurHash3.h
	functions/MurmurHash3.cpp
	functions/lookup3.h
	functions/lookup3.cpp
	functions/JenkinsOAAT.h
	functions/JenkinsOAAT.cpp
	functions/fnv1a_32.h
	functions/fnv1a_32.cpp
	functions/AnveCMD_Hash.h
	functions/AnveCMD_Hash.cpp
	functions/AnveHashMap_Hash.h
	functions/AnveHashMap_Hash.cpp
	tester.h
	tester.cpp
	main.cpp
)
add_executable(${PROJECT_NAME} ${APP_SRC})
target_link_libraries(${PROJECT_NAME})

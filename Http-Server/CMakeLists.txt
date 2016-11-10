cmake_minimum_required(VERSION 3.6)
project(Http_Server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Response/Response.cpp Response/Response.h Request/Request.cpp Request/Request.h Linker/Linker.cpp Linker/Linker.h Server/Server.cpp Server/Server.h Parser/Parser.cpp Parser/Parser.h WebLogic/WebLogic.cpp WebLogic/WebLogic.h ResponseCreater/ResponseCreater.cpp ResponseCreater/ResponseCreater.h ResourceReader/ResourceReader.cpp ResourceReader/ResourceReader.h)

add_executable(Http_Server ${SOURCE_FILES})
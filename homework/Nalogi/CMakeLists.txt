cmake_minimum_required(VERSION 3.26)
project(Nalogi)

set(CMAKE_CXX_STANDARD 17)

add_executable(Nalogi main.cpp
        income.h
        headers.h
        incomeTypes.h
        taxes.h)

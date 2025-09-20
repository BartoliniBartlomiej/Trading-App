cmake_minimum_required(VERSION 4.0)
project(tradingPlatform)

set(CMAKE_CXX_STANDARD 20)

add_executable(tradingPlatform main.cpp
        user.cpp
        user.h
        Transaction.cpp
        Transaction.h
        market.cpp
        market.h
        item.cpp
        item.h
)

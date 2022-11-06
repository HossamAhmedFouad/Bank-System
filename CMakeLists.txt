cmake_minimum_required(VERSION 3.21)
project(Bank_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Bank_System
        BankAccount.cpp
        BankApplication.cpp
        BankSystem_Classes.h
        Client.cpp
        SavingsBankAccount.cpp
        testing.cpp)

cmake_minimum_required(VERSION 3.26)
project(ProyectoFinal)

set(CMAKE_CXX_STANDARD 17)

add_executable(ProyectoFinal main.cpp
        User/User.cpp
        User/User.h
        User/UsersList.cpp
        User/UsersList.h
        Book/Book.cpp
        Book/Book.h
        Book/BooksList.cpp
        Book/BooksList.h
)

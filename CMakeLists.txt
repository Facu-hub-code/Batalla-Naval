cmake_minimum_required(VERSION 3.19)
project(Codigo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Codigo main.cpp Tablero.cpp Tablero.h Barco.cpp Barco.h PilaDePos.cpp PilaDePos.h ColaDePilas.cpp ColaDePilas.h Juego.cpp Juego.h Posicion.cpp Posicion.h)
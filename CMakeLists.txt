cmake_minimum_required(VERSION 3.19)
project(Codigo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Codigo JuegoMain.cpp Tablero.cpp Tablero.h Barco.cpp Barco.h Pila.cpp Pila.h Cola.cpp Cola.h Posicion.cpp Posicion.h)
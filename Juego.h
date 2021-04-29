//
// Created by patri on 29/04/2021.
//
#import "Tablero.h"
#import "Barco.h"
#import "ColaDePilas.h"
#ifndef CODIGO_JUEGO_H
#define CODIGO_JUEGO_H


class Juego {
public:
       Juego::Juego(){  //constructor
          Tablero* tablero= new  Tablero();


       }


private:
       Tablero* tablero;
       Barco barcos[10];
       ColaDePilas disparos;


};


#endif //CODIGO_JUEGO_H

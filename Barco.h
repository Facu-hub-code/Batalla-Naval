//
// Created by patri on 29/04/2021.
//
#include <string>
#ifndef CODIGO_BARCO_H
#define CODIGO_BARCO_H
#include "Posicion.h"

class Barco {
public:
    Barco(char tipo, Posicion posBarco[4]){
         this -> tipo = tipo;
         this -> posBarco[4]=posBarco[4];



     }
private:
    Posicion posBarco[4];
    char tipo;//Crucero, submarino, etc
    char estado;//averiado, hundido, agua


};


#endif //CODIGO_BARCO_H

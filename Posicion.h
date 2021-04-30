//
// Created by patri on 29/04/2021.
//

#ifndef CODIGO_POSICION_H
#define CODIGO_POSICION_H


typedef struct{
 int x;
 int y;
 bool ocupado;
 char estado;
}posStruct;

class Posicion {

private:
    posStruct pos;
public:
    Posicion(){}
    int getX() const {return pos.x;}
    int getY() const {return pos.y;}
    bool isOcupado() const {return pos.ocupado;}
    //const posStruct &getPos() const {return pos;}

    //Setters
    void setEstado(char estado) {pos.estado = estado;}
    void setX(int cx) {pos.x=cx;}
    void setY(int cy) {pos.y=cy;}
    void setXY(int cx, int cy) {pos.x = cx;pos.y = cy;}
    void setOcupado(bool ocupado) {pos.ocupado=ocupado;}
    void setPos(const posStruct &pos) {Posicion::pos = pos;}
};


#endif //CODIGO_POSICION_H

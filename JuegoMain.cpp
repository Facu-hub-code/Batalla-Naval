/*
 * El juego de la batalla naval consiste en un tablero de 10 x 10 casilleros donde uno dispone barcos y que el
 * contrincante debe “hundirlo” indicando las posiciones (fila,columna) donde lanza “bombas”.
 */
#include <iostream>
#include "Tablero.h"
#import "Barco.h"
#import "Cola.h"

void inicializar();
using namespace std;
//Prototipos
void inicializar();

int main() {
    inicializar();
    return 0;
}
void inicializar() {
    Tablero tablero = Tablero();
    Barco barcos[10];
    for (int i = 0; i < 10; ++i) {
        //creo un barco
        cout<<"Barco ["<<i<<"]"<<endl;
        barcos[i] = Barco();
        //creo la primera posicion del barco
        Posicion posAux = Posicion();
        cout<<"Ingrese primer coordenada [X ; Y]"<<endl;
        int x,y;
        cin>>x>>y;
        posAux.setXY(x,y);
        posAux.setOcupado(true);
        posAux.setEstado(NULL);
        //Aca ya tengo la primera posicion del barco.
        barcos[i].setPos(posAux,0); //seteo la posicion inicial

        cout<<"Ingrese una direccion (para completar el barco)\n Pueden ser: [Up:U, Down:D, Left:L, Right:R]"<<endl;
        char direc;
        cin>>direc;

        cout<<"Ingrese el tipo de Barco: [C:Crucero, D:Destructor, S:Submarino, c:Canonero]"<<endl;
        char tipo;
        cin>>tipo;

        switch (tipo) {
            case 'D':
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY()+1);
                            barcos[i].setPos(posAux, i+1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;

                }

            case 'C':
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY()+1);
                            barcos[i].setPos(posAux, i+1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                }
            case 'c':
                switch (direc) {
                    case 'U':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY()+1);
                            barcos[i].setPos(posAux, i+1);
                        }
                        break;
                    case 'D':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'L':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                    case 'R':
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, i + 1);
                        }
                        break;
                }break;
        }
    }
}
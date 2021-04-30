/*
 * El juego de la batalla naval consiste en un tablero de 10 x 10 casilleros donde uno dispone barcos y que el
 * contrincante debe “hundirlo” indicando las posiciones (fila,columna) donde lanza “bombas”.
 */
#include <iostream>
#include "Tablero.h"
#import "Barco.h"
#import "Cola.h"
using namespace std;

//Variables globales.
Tablero tablero = Tablero();
Barco barcos[10];
bool juegoFinalizado = false;
int commit=0;

//Prototipos
void ini();
void inicializar();

void disparar();

//METODO PRINCIPAL
int main() {
    inicializar();
    for (int i = 0; i < 2; ++i) {
        barcos[i].printDeEstado();
    }
    cout<<"El valor de X es: "<<barcos[0].getPosicion(2).getX()<<endl;
    //disparar();
    return 0;
}

/*
 * Este metodo inicializa 10 Barcos pidiendo por consola una POSICION de referencia, una DIRECCION y un TIPO de barco.
 * El algoritmo completa 4 lugares segun sea el tipo (ej el Destructor ocupa 4, y el submarino solo 1).
 * Dichas posiciones se completan segun se indique la direccion (ej char Direccion = U -> significa UP:Arriba).
 * Ej: si ingreso {[4 ; 4] ; U ; D} obtendre ocupadas las posiciones: [4,4] [4,5] [4,6] [4,7] por un DESTRUCTOR.
 */

void inicializar() {
    for (int i = 0; i < 2; ++i) {
        cout<<"Barco ["<<i<<"]"<<endl;

        //Obetenemos la posicion inicial de referencia.
        cout<<"Ingrese la coordenada de referencia inicial [X ; Y]\n (Ingrese X -> ENTER -> Y -> ENTER)"<<endl;
        int x,y;
        cin>>x>>y;
        Posicion posAux = Posicion(x,y);

        cout<<"Ingrese una direccion (para completar el barco)\n Pueden ser: [Up:U, Down:D, Left:L, Right:R]"<<endl;
        char direc;
        cin>>direc;

        cout<<"Ingrese el tipo de Barco: [C:Crucero, D:Destructor, S:Submarino, c:Canonero]"<<endl;
        char tipo;
        cin>>tipo;
        Barco barAux(posAux, tipo);
        barcos[i] = barAux;

        //Decodificar tipo y Direccion.
        if(tipo=='D') {
            if(direc=='U') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setY(posAux.getY() + 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='D') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setY(posAux.getY() - 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='L') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setX(posAux.getX() - 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='R') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setX(posAux.getX() + 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            else{
                    cout<<"Se ingreso una direccion invalida."<<endl;

            }
        }


        if(tipo=='C'){
            if(direc=='U') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setY(posAux.getY() + 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='D') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setY(posAux.getY() - 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='L') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setX(posAux.getX() - 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='R') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setX(posAux.getX() + 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
        if(tipo=='c'){
            if(direc=='U') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setY(posAux.getY() + 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='D') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setY(posAux.getY() - 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='L') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setX(posAux.getX() - 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            if(direc=='R') {

                for (int j = 0; j < 3; ++j) {
                    posAux.setX(posAux.getX() + 1);
                    barcos[i].setPos(posAux, j + 1);
                }
            }
            else{
                cout<<"Se ingreso una direccion invalida."<<endl;

            }
        }
        else{
                cout<<"Se ingreso una direccion invalida."<<endl;

            }
        }





        }
    }

void disparar(){

}
//TODO: para sumar puntos revisar los overflow del tablero.
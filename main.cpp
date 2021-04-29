#include <iostream>
#include "Tablero.h"
#import "Barco.h"
#import "ColaDePilas.h"
using namespace std;

int main() {
    Tablero tablero=Tablero();
    ColaDePilas* disparos= new ColaDePilas();
    //Creamos los 10 barcos
    for (int i = 0; i < 10; ++i) {
        Barco barco=Barco();

        cout<<"Estamos en el barco:"<<i<<endl;
        for (int j = 0; j < 4; ++j) {
            Posicion posAuxx= Posicion();
            cout<<"Ingrese las 4 posiciones [x][y], tipo(char): D(Destructor), c(cañonero), S(submarino), C(crucero) del barco y su booleano(pos ocupado o no):"<<endl;
            barco.setPos()
            cin>>;
        }




    }

    return 0;
}

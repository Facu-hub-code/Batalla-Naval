/*
 * El juego de la batalla naval consiste en un tablero de 10 x 10 casilleros donde uno dispone barcos y que el
 * contrincante debe “hundirlo” indicando las posiciones (fila,columna) donde lanza “bombas”.
 */
#include <iostream>
#include "Tablero.h"
#import "Barco.h"
#import "Cola.h"
#include "Pila.h"
using namespace std;


Tablero tablero = Tablero(); //Se guardan los disparos
Barco barcos[9]; //se ejecuta el constructor por defecto de cada barco.
bool juegoFinalizado = false;
int const cantDisparosMAX = 20;
int const cantidadDeBarcos = 10;
Pila pilaPosiciones = Pila();

//Prototipos
void inicializarPorConsola();
void inicializarPorDefecto();
void jugar();
void disparar();
//TODO: contemplar v,a,a,a -> saltar a otra pila
//TODO: contempalr si es ej horizontal, y [4,4]v ; [3,4]v ; [2,4]a ir directamente a [5,4]v
//TODO: si todavia no lo hundio apilar [6,4]

int main() {
    //Guardar los barcos en el juego y printearlos
    inicializarPorDefecto();

    //Realizar los disparos y sus siguientes.
    jugar();

    //Print resumen del GAME OVER
    tablero.printDisparos();

    return 0;
}

/*
 * Este metodo inicializa los barcos por defecto en posiciones predefinidas.
 */
void inicializarPorDefecto(){
    //Canoneros
    // c0:pc00[1,1]  pc01[1,2]
    Posicion posc00 = Posicion(1, 1, true);
    Barco barcoc0 = Barco(posc00, 'c');
    Posicion posc01 = Posicion(1, 2,true);
    barcoc0.setPos(posc01, 1);
    //c1:pc02[10,3]  pc03[10,4]
    Posicion posc02 = Posicion(10, 3,true);
    Barco barcoc1 = Barco(posc02, 'c');
    Posicion posc03 = Posicion(10,4,true);
    barcoc1.setPos(posc03, 1);
    //Submarinos
    //S1:[1,10]
    Posicion posS1 = Posicion(1,10,true);
    Barco barcoS1 = Barco(posS1, 'S');
    //S2:[10,10]
    Posicion posS2 = Posicion(10,10,true);
    Barco barcoS2 = Barco(posS2, 'S');
    // S3:[10,1]
    Posicion posS3 = Posicion(10,1,true);
    Barco barcoS3 = Barco(posS3, 'S');
    //Destructor
    // [4,3], [4,4],[4,5],[4,6]
    Posicion posD0 = Posicion(4,3,true);
    Barco barcoD0 = Barco(posD0, 'D');
    Posicion posD1 = Posicion(4,4,true);
    barcoD0.setPos(posD1, 1);
    Posicion posD2 = Posicion(4,5,true);
    barcoD0.setPos(posD2, 2);
    Posicion posD3 = Posicion(4,6,true);
    barcoD0.setPos(posD3, 3);
    //Cruceros
    //C1:[6,3],[7,3],[8,3]
    Posicion posC1 = Posicion(6,3,true);
    Barco barcoC1 = Barco(posC1, 'C');
    Posicion posC2 = Posicion(7,3,true);
    barcoC1.setPos(posC2, 1);
    Posicion posC3 = Posicion(8,3,true);
    barcoC1.setPos(posC3, 2);
    //C2:[7,9],[8,9],[9,9]
    Posicion posC01 = Posicion(7,9,true);
    Barco barcoC2 = Barco(posC01, 'C');
    Posicion posC02 = Posicion(8,9,true);
    barcoC2.setPos(posC02, 1);
    Posicion posC03 = Posicion(9,9,true);
    barcoC2.setPos(posC03, 2);

    cout<<endl<<endl<<endl<<"~TABLERO~"<<endl<<endl;

    cout<<"   1   2   3   4   5   6   7   8   9   10"<<endl;
    cout<<"10 S   -   -   -   -   -   -   -   -   S"<<endl;
    cout<<"9  -   -   -   -   -   -   C   C   C   -"<<endl;
    cout<<"8  -   -   -   -   -   -   -   -   -   -"<<endl;
    cout<<"7  -   -   -   -   -   S   -   -   -   -"<<endl;
    cout<<"6  -   -   -   D   -   -   -   -   -   -"<<endl;
    cout<<"5  -   -   -   D   -   -   -   -   -   -"<<endl;
    cout<<"4  -   -   -   D   -   -   -   -   -   c"<<endl;
    cout<<"3  -   -   -   D   -   C   C   C   -   c"<<endl;
    cout<<"2  c   -   -   -   -   -   -   -   -   -"<<endl;
    cout<<"1  c   -   -   -   -   -   -   -   -   S"<<endl<<endl<<endl;
}

/*
 * Este metodo apunta a una posicion de la cola de posiciones para realizar un disparo.
 * Dependiendo de la respuesta del usuario calcula el siguiente disparo.
 */
void jugar() {
    int contador = 0;
    while (!juegoFinalizado) {
        //Coordenadas de la nueva posicion a disparar
        int ranX = 1 + rand() % (10 - 1 + 1);
        int ranY = 1 + rand() % (10 - 1 + 1);
        Posicion* posAux = new Posicion(ranX, ranY, false);
        pilaPosiciones.setComienzo(posAux);
        //posAux.siguiente->setXY(ranX, ranY); //EXC_BAD_ACCESS (code=1, address=0x0)
        Cola *colaPosiciones = new Cola(posAux);
        //TODO: comienzo tendriaa que apuntar a posAux.

        cout << "Disparo a la posicion: [" << ranX << " ; " << ranY << " ]" << endl;
        tablero.setDisparo(ranX,ranY);
        disparar();

        //Si no fue un acierto, cuento el disparo en el contado y vuelvo a ingresar al while.
        contador++;
        if (contador == cantDisparosMAX) {
            juegoFinalizado = true;
        } else {
            cout << "Se intentara otro disparo..." << endl;
        }
    }
    cout << "GAME OVER" << endl;
}


void disparar(){
    cout<<"Fue un acierto? [Agua:a, Averiado:v, Hundido:h]"<<endl;
    char estado;
    cin >> estado;
    if(estado == 'v'){
        cout<<"\tCuidado..."<<endl;
        //Recupero las coordenadas del primer disparo acertado de la Pila actual.
        int ranX = pilaPosiciones.getComienzo()->getX();
        int ranY = pilaPosiciones.getComienzo()->getY();

        //Apilo posiciones alrededor del priemr disparo acertado de la Pila actual.
        pilaPosiciones.add(ranX,ranY+1, false);
        pilaPosiciones.add(ranX,ranY-1, false);
        pilaPosiciones.add(ranX+1,ranY, false);
        pilaPosiciones.add(ranX-1,ranY, false);  //LEFT es el TOPE

        while(estado == 'v'){   //Mientras este averiado, disparo a los alrededores.
            //TODO:IMplementar getSiguiente en clase PILA
            int xAux,yAux;
            xAux = pilaPosiciones.getComienzo()->siguiente->getX();
            yAux = pilaPosiciones.getComienzo()->siguiente->getY();
            cout << "Disparo a la posicion: [" << xAux<< " ; "<< yAux << " ]" << endl; //Disparo al TOPE de la Pila Actual.
            tablero.setDisparo(xAux, yAux);
            cout<<"Ingrese el estado del reciente disparo: [Agua:a, Averiado:v, Hundido:h]:_";
            cin>>estado;

            if(estado == 'h'){
                cout<<"\tVamos !!!"<<endl;
            }

            /*
             * 4.3)Si es averiado, (caso de barcos grandes), hay que apilar la siguiente posición en la linea del barco,
             * porque ya se sabe que direccion tiene el barco, y vuelvo a disparar usando la pila actual.
             */
            if(estado == 'v'){
                cout<<"Cuidado..."<<endl;
                //recupero pos 2do disparo para buscar la direccion [HORIZONTAL VERTICAL] A Apilar.
                int ranX2 = pilaPosiciones.getComienzo()->getX();
                int ranY2 = pilaPosiciones.getComienzo()->getY();
                int direccionX= ranX - ranX2; //Me fijo si esta horizontal
                switch (direccionX) {
                    case -1: //Se movio para la Derecha
                        pilaPosiciones.add(ranX+1,ranY, false);
                        break;
                    case 1: //Se movio para la Izquierda.
                        pilaPosiciones.add(ranX-1,ranY, false); //Nuevo TOPE LEFT
                        break;
                    case 0: //Se movio en vertical
                        int direccionY = ranY-ranY2;
                        if(direccionY == -1){ //Se movio para Arriba
                            pilaPosiciones.add(ranX,ranY+1, false);
                        }if(direccionY == 1){ //Se movio para Abajo
                            pilaPosiciones.add(ranX,ranY-1, false);
                        }
                        break;
                }
            }if(estado == 'a'){ //4.1)Si es agua, sigo con el proximo de la pila.
                cout<<"Suerte la proxima!"<<endl;
                pilaPosiciones.borrar(); //borro la Posicion cabeza.
                estado = 'v';
            }
        }
    }
    if(estado == 'h'){
        cout<<"VAMOS, hundido a la primera"<<endl;
    }
}
/*
 * Este metodo inicializa 10 Barcos pidiendo por consola una POSICION de referencia, una DIRECCION y un TIPO de barco.
 * El algoritmo completa 4 lugares segun sea el tipo (ej el Destructor ocupa 4, y el submarino solo 1).
 * Dichas posiciones se completan segun se indique la direccion (ej char Direccion = U -> significa UP:Arriba).
 * Ej: si ingreso {[4 ; 4] ; U ; D} obtendre ocupadas las posiciones: [4,4] [4,5] [4,6] [4,7] por un DESTRUCTOR.
 */
void inicializarPorConsola() {
    for (int i = 0; i < cantidadDeBarcos; ++i) {
        cout<<"Barco ["<<i<<"]"<<endl;
        //Obetenemos la posicion inicial de referencia.
        cout<<"Ingrese la coordenada de referencia inicial [X ; Y]"<<endl;
        int x,y;
        cin>>x>>y;
        Posicion posAux = Posicion(x,y,true);
        cout<<"Ingrese una direccion (para completar el barco)\n Pueden ser: [Up:U, Down:D, Left:L, Right:R]"<<endl;
        char direc;
        cin>>direc;

        cout<<"Ingrese el tipo de Barco: [C:Crucero, D:Destructor, S:Submarino, c:Canonero]"<<endl;
        char tipo;
        cin>>tipo;
        Barco barAux(posAux, tipo);
        barcos[i] = barAux;

        //Decodificar tipo y Direccion.
        switch(tipo) {
            case 'D': //DESTRUCTOR
                switch (direc) {
                    case 'U'://UP
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'D'://DOWN
                        for (int j = 0; j < 3; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'L'://LEFT
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'R'://RIGHT
                        for (int j = 0; j < 3; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                }
                break;
            case 'C'://CRUCERO
                switch (direc) {
                    case 'U'://UP
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'D'://DOWN
                        for (int j = 0; j < 2; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'L'://LEFT
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'R'://RIGHT
                        for (int j = 0; j < 2; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                }
                break;
            case 'c':
                switch (direc) {
                    case 'U': //UP
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'D'://DOWN
                        for (int j = 0; j < 1; ++j) {
                            posAux.setY(posAux.getY() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'L'://LEFT
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() - 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                    case 'R': //RIGHT
                        for (int j = 0; j < 1; ++j) {
                            posAux.setX(posAux.getX() + 1);
                            barcos[i].setPos(posAux, j + 1);
                        }
                        break;
                }
                break;
        }
    }
}

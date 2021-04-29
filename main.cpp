#include <iostream>
using namespace std;
#include "Tablero.h"
int main() {
    cout<<"Hello world"<<endl;
    Tablero* tablero = new Tablero();
    cout<<tablero->getI();
    return 0;
}

#include <iostream>
#include <thread>
#include <string>
#include <cmath>
#include <functional>
using namespace std;

//Calcular b cuadrada
void bSquare(int b, int& resultado) {
    resultado = b * b;
}

//Calcular 4ac
void fourAC (int a, int c, int& resultado) {
    resultado = 4 * a * c;
}

void calcularX1 (int a, int b, int D, double& resultado){
    resultado = (-b + sqrt((double)D)) / (2.0 * a);
}

void calcularX2 (int a, int b, int D, double& resultado){
    resultado = (-b - sqrt((double)D)) / (2.0 * a);
}

//calcular determinante

int main(){
    int a = 1, b = 2, c = 3;
    int bCuadrada = 0, cuatroAC = 0;

    if (a != 0){

        thread h1(bSquare, b, ref(bCuadrada));
        thread h2(fourAC, a, c, ref(cuatroAC));
        h1.join();
        h2.join();

        int D = bCuadrada - cuatroAC;

        if(D > 0){
            //calcular x1 y x2 paralelo
            double x1, x2;

            thread h3(calcularX1, a, b, D, ref(x1));
            thread h4(calcularX2, a, b, D, ref(x2));
            h3.join();
            h4.join();

            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;

        }else if (D == 0){
            //calcular x
            double x = -b / (2.0 * a);
            cout << "x = " << x << endl;

        }else if (D < 0){
            cout << "No existen raíces reales" << endl;
        }else{
            cout << "Indeterminado" << endl;
        }
    }

    return 0;


}
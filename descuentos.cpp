#include <iostream>
#include <thread>
#include <functional>

using namespace std;

void verifica1000(double totalCompra, bool& resultado){
    if (totalCompra >= 1000){
        resultado = true;
    }
}
void verifica1500(double totalCompra, bool& resultado){
    if (totalCompra >= 1500){
        resultado = true;
    }
}

void verificaAntiacido( int antiacidos, bool& resultado){
    if (antiacidos > 0){
        resultado = true;
    }
}

int main(){

    bool cumple1000 = false, cumple1500 = false, cumpleAntiacido = false;
    int antiacidos = 1; 
    double totalCompra = 1240.00, precioFinal;

    thread h1(verifica1000, totalCompra, ref(cumple1000));
    thread h2(verifica1500, totalCompra, ref(cumple1500));
    thread h3(verificaAntiacido, antiacidos, ref(cumpleAntiacido));

    h1.join();
    h2.join();
    h3.join();

    if (cumple1500 == true){
        precioFinal = totalCompra * 0.7;
    } else if (cumple1000 == true){
        precioFinal = totalCompra * 0.8;
    } else if (cumpleAntiacido == true){
        precioFinal = totalCompra * 0.9;
    }else{
        precioFinal = totalCompra;
    }

    cout << "Total: " << totalCompra << endl;
    cout << "Total con descuento: " << precioFinal << endl;

    return 0;

}
#include <iostream>
#include <vector>
#include <thread>
#include <functional>
using namespace std;

void invertirArreglo(vector<int>& arr, int start, int end) {
    swap(arr[start], arr[end]);
}

int main() {
    vector<thread> hilos;
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    int swaps = n / 2;

    cout << "Arreglo original: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < swaps; i++) {
        hilos.emplace_back(invertirArreglo, ref(arr), i, n - 1 - i);
        cout << "Hilo " << i << " ejecutándose" << endl;
    }
    for (auto& hilo : hilos) {
        hilo.join();
    }

    cout << "Arreglo invertido: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

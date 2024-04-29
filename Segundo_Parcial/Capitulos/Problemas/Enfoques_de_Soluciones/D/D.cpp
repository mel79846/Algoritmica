#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 

// Define una constante entera "MAX_N" con un valor de 10000.
const int MAX_N = 10000;

// Crea un vector de enteros "cycleLengths" con un tamaño de MAX_N + 1 y todos los elementos inicializados en cero.
vector<int> cycleLengths(MAX_N + 1, 0);

// Esta es una función que calcula la longitud del ciclo de un número entero "n".
int calculateCycleLength(int n) {
    int length = 1; // inicializa la variable "length" a uno para calcular la longitud del ciclo
    while (n != 1) { // este ciclo while se repite hasta que "n" sea igual a 1
        if (n % 2 == 0) { // si "n" es par
            n = n / 2; // se divide por dos
        } else { // si "n" es impar
            n = 3 * n + 1; // se multiplica por tres y se suma uno
        }
        ++length; // se incrementa la longitud del ciclo en uno
    }
    return length; // devuelve la longitud del ciclo
}

// Esta es una función que encuentra la longitud del ciclo más largo entre dos números enteros "i" y "j".
int findMaxCycleLength(int i, int j) {
    int maxCycle = 0; // inicializa la variable "maxCycle" a cero para calcular la longitud del ciclo más largo
    for (int num = min(i, j); num <= max(i, j); ++num) { // este ciclo for se repite desde el mínimo de "i" y "j" hasta el máximo de "i" y "j"
        if (num <= MAX_N && cycleLengths[num] != 0) { // si el ciclo de "num" ya ha sido calculado
            maxCycle = max(maxCycle, cycleLengths[num]); // se actualiza la longitud del ciclo más largo
        } else { // si el ciclo de "num" no ha sido calculado
            int currentCycle = calculateCycleLength(num); // se calcula su longitud
            maxCycle = max(maxCycle, currentCycle); // se actualiza la longitud del ciclo más largo
            if (num <= MAX_N) { // se almacena la longitud del ciclo de "num" en el vector "cycleLengths" si "num" es menor o igual a MAX_N
                cycleLengths[num] = currentCycle;
            }
        }
    }
    return maxCycle; // devuelve la longitud del ciclo más largo
}

// Esta es la función principal del programa, donde se ejecuta el código principal.
int main() {
    int i, j; // declara dos variables enteras "i" y "j"
    while (cin >> i >> j) { // este ciclo while se repite hasta que se haya leído un par de valores enteros válidos
        cout << i << " " << j << " " << findMaxCycleLength(i, j) << endl; // imprime el par de valores enteros y la longitud del ciclo más largo entre ellos
    }
    return 0; 
}

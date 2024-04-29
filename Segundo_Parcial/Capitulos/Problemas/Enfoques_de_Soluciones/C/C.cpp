#include <iostream> 
#include <vector> 
using namespace std; 

// Esta es una función que calcula la cantidad total de monedas de oro que se pueden obtener en un número determinado de días.
int total_gold_coins(int days) {

    int coins = 0; // inicializa la variable "coins" a cero para calcular la cantidad total de monedas de oro
    int cycle_length = 1; // inicializa la variable "cycle_length" a uno para calcular la longitud del ciclo actual

    while (days > 0) { // este ciclo while se repite hasta que se hayan procesado todos los días

        if (days < cycle_length) { // si el número de días restantes es menor que la longitud del ciclo actual
            coins += days * cycle_length; // calcula la cantidad de monedas de oro obtenidas en la parte no completa del ciclo y las agrega a la cantidad total de monedas de oro
            days = 0; // establece el número de días restantes a cero para terminar el ciclo actual

        } else { // si el número de días restantes es mayor o igual que la longitud del ciclo actual

            coins += cycle_length * cycle_length; // calcula la cantidad de monedas de oro obtenidas en un ciclo completo y las agrega a la cantidad total de monedas de oro
            days -= cycle_length; // actualiza el número de días restantes después de procesar un ciclo completo
            cycle_length++; // actualiza la longitud del ciclo después de procesar un ciclo completo
        }
    }

    return coins; // devuelve la cantidad total de monedas de oro obtenidas
}

int main() { // define la función principal del programa
    int N; // declara una variable entera "N" para almacenar el número de casos de prueba
    cin >> N; // lee el número de casos de prueba

    for (int i = 0; i < N; ++i) { // este ciclo for se repite "N" veces, una vez por cada caso de prueba
        vector<int> test_cases; // crea un vector de enteros para almacenar los casos de prueba

        while (cin >> N && N != 0) { // este ciclo while se repite hasta que se haya leído un caso de prueba válido (no cero)
            test_cases.push_back(N); // agrega el caso de prueba al vector de casos de prueba
        }

        for (int day : test_cases) { // este ciclo for se repite una vez por cada caso de prueba en el vector de casos de prueba
            cout << day << " " << total_gold_coins(day) << endl; // imprime el caso de prueba y la cantidad total de monedas de oro obtenidas en ese caso de prueba
        }

        if (i < N - 1) { // si no es el último caso de prueba
            cout << endl; // agrega un salto de línea entre cada caso de prueba
        }
    }

    return 0; 
}

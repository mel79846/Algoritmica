#include <iostream> 
using namespace std; 

int main() { 
    int n; // declara una variable entera "n" para almacenar el número de casos de prueba

    while (cin >> n && n != -1) { // este ciclo while se repite hasta que el usuario ingrese "-1" como el número de casos de prueba

        int speed, elapsed; // declara dos variables enteras "speed" y "elapsed" para almacenar la velocidad y el tiempo transcurrido en cada caso de prueba
        int startTime = 0; // inicializa la variable "startTime" a cero para almacenar el tiempo de inicio de cada caso de prueba
        int result = 0; // inicializa la variable "result" a cero para calcular la distancia total recorrida en cada caso de prueba
        
        for (int i = 0; i < n; i++) { // este ciclo for se repite "n" veces, una vez por cada caso de prueba

            cin >> speed >> elapsed; // lee la velocidad y el tiempo transcurrido en cada caso de prueba y los almacena en las variables "speed" y "elapsed"
            int currentTime = elapsed - startTime; // calcula el tiempo transcurrido desde el inicio del caso de prueba hasta el momento actual y lo almacena en la variable "currentTime"
            result += speed * currentTime; // calcula la distancia recorrida en el intervalode tiempo actual y la agrega a la distancia total recorrida en el caso de prueba
            startTime = elapsed; // actualiza el tiempo de inicio del caso de prueba al tiempo transcurrido en el momento actual
        }
        
        cout << result << " miles" << endl; // imprime la distancia total recorrida en el caso de prueba
    }
    
    return 0; 
}

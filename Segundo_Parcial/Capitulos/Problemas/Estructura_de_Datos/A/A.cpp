#include<bits/stdc++.h> 

using namespace std; 
#define input freopen("in.txt","r",stdin) 
#define output freopen("out.txt","w",stdout)

int main() { 
    input; // Descomentar esta línea para redirigir la entrada estándar a un archivo llamado "in.txt".
    output; // Descomentar esta línea para redirigir la salida estándar a un archivo llamado "out.txt".
    int numCar; // Declara una variable entera "numCar" para almacenar el número de automóviles.

    while(cin>>numCar && numCar) { // Este ciclo while se repite hasta que se haya leído un valor entero válido y este sea distinto de cero.
        vector<pair<int, int>> cars(numCar); // Crea un vector de pares de enteros "cars" con un tamaño de "numCar".

        for(int i = 0; i < numCar; i++){ // Este ciclo for se repite "numCar" veces, una vez por cada par de enteros en el vector "cars".
            int car, finalPos; // Declara dos variables enteras "car" y "finalPos" para almacenar el número de automóvil y su posición final deseada.
            cin >> car >> finalPos; // Lee dos valores enteros desde la entrada estándar y los almacena en las variables "car" y "finalPos".
            cars[i] = make_pair(car, finalPos); // Almacena el par de enteros leído en el vector "cars" en la posición "i".
        }

        vector<int> positions(numCar, 0); // Crea un vector de enteros "positions" con un tamaño de "numCar" y todos los elementos inicializados en cero.
        bool noSolution = false; // Inicializa la variable booleana "noSolution" a falso.

        for(int i = 0; i < numCar; i++) { // Este ciclo for se repite "numCar" veces, una vez por cada par de enteros en el vector "cars".
            int car = cars[i].first; // Extrae el número de automóvil del par en la posición "i" del vector "cars" y lo almacena en la variable "car".
            int finalPos = cars[i].second; // Extrae la posición final deseada del par en la posición "i" del vector "cars" y lo almacena en la variable "finalPos".

            if((i + finalPos) % numCar == 0 || positions[i + finalPos] != 0) { // Este if se utiliza para verificar si el automóvil puede ser colocado en la posición final deseada sin colisionar con otros automóviles.
                noSolution = true; // Si el automóvil no puede ser colocado en la posición final deseada, se establece la variable "noSolution" a verdadero.
                break; // Se sale del ciclo for.
            }

            positions[i + finalPos] = car; // Si el automóvil puede ser colocado en la posición final deseada, se almacena el número de automóvil en la posición correspondiente del vector "positions".
        }

        if(noSolution){ // Este if-else se utiliza para imprimir la solución o indicar que no existe una solución.
            cout << -1 << endl; // Si no existe una solución, se imprime "-1" seguido de un salto de línea.
        } else {
            cout << positions[0]; // Si existe una solución, se imprime el número de automóvil en la primera posición.
            for(int i = 1; i < numCar; i++){ // Este ciclo for se repite "numCar" veces, una vez por cada posición en el vector "positions".
                cout << " " << positions[i]; // Se imprime el número de automóvil en la posición actual.
            }
            cout << endl; // Se imprime un salto de línea después de imprimir todos los números de automóviles.
        }
    }
       
    return 0; 
}

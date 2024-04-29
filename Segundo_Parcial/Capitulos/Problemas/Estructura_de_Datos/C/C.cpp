#include<bits/stdc++.h> 

using namespace std; 

// Esta función verifica si una secuencia de enteros es "jolly" o no.
bool isJolly(const vector<int>& sequence) {
    int n = sequence.size(); // Obtiene el tamaño de la secuencia de enteros.

    if (n == 1) // Si la secuencia tiene solo un elemento, se considera "jolly".
        return true;

    unordered_set<int> differences; // Crea un conjunto desordenado de enteros "differences" para almacenar 
                                       las diferencias entre los elementos consecutivos de la secuencia.
    for (int i = 1; i < n; ++i) { // Este ciclo for se repite "n - 1" veces, una vez por cada par de elementos consecutivos en la secuencia.
        int diff = abs(sequence[i] - sequence[i - 1]); // Calcula la diferencia entre los elementos consecutivos de la secuencia.
        if (diff == 0 || diff >= n || differences.count(diff)) // Si la diferencia es cero, mayor o igual que "n" o ya está en el conjunto "differences", 
                                                                  se devuelve falso.
            return false;
        differences.insert(diff); // Si la diferencia no está en el conjunto "differences", se agrega al conjunto.
    }
    return differences.size() == n - 1; // Si el tamaño del conjunto "differences" es igual a "n - 1", se devuelve verdadero. De lo contrario, se devuelve falso.
}

int main() { 
    int n; // Declara una variable entera "n".

    while (cin >> n) { // Este ciclo while se repite hasta que se haya leído un valor entero válido.
        vector<int> sequence(n); // Crea un vector de enteros "sequence" con un tamaño de "n".

        for (int i = 0; i < n; ++i) { // Este ciclo for se repite "n" veces, una vez por cada elemento en el vector "sequence".
            cin >> sequence[i]; // Lee un valor entero desde la entrada estándar y lo almacena en el vector "sequence" en la posición "i".
        }
        if (isJolly(sequence)) // Si la secuencia es "jolly", se imprime "Jolly".
            cout << "Jolly" << endl;
        else // De lo contrario, se imprime "Not jolly".
            cout << "Not jolly" << endl;
    }
    return 0; 
}

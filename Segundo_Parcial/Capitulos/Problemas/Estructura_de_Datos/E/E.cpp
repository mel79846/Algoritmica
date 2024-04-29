#include<bits/stdc++.h> 

using namespace std; 

int main() { 
    int n, s; // Declara dos variables enteras "n" y "s".
    cin >> n >> s; // Lee dos valores enteros "n" y "s" desde la entrada estándar.

    vector<int> first_track(n), second_track(n); // Crea dos vectores de enteros "first_track" y "second_track" con un tamaño de "n".
    for (int i = 0; i < n; ++i) { // Este ciclo for se repite "n" veces, una vez por cada elemento en los vectores "first_track" y "second_track".
        cin >> first_track[i]; // Lee un valor entero desde la entrada estándar y lo almacena en el vector "first_track" en la posición "i".
    }
    for (int i = 0; i < n; ++i) { // Este ciclo for se repite "n" veces, una vez por cada elemento en los vectores "first_track" y "second_track".
        cin >> second_track[i]; // Lee un valor entero desde la entrada estándar y lo almacena en el vector "second_track" en la posición "i".
    }

    if (first_track[0] == 0) { // Si el primer elemento del vector "first_track" es cero, se imprime "NO" y se finaliza la ejecución.
        cout << "NO" << endl; 
        return 0;
    }

    if (first_track[s - 1] == 1) { // Si el elemento en la posición "s - 1" del vector "first_track" es uno, se imprime "YES" y se finaliza la ejecución.
        cout << "YES" << endl; 
        return 0;
    }

    if (second_track[s - 1] == 0) { // Si el elemento en la posición "s - 1" del vector "second_track" es cero, se imprime "NO" y se finaliza la ejecución.
        cout << "NO" << endl; 
        return 0;
    }

    for (int i = s; i < n; ++i) { // Este ciclo for se repite "n - s" veces, una vez por cada elemento en los vectores "first_track" y "second_track" desde la posición "s" hasta el final.
        if (first_track[i] == 1 && second_track[i] == 1) { // Si el elemento en la posición "i" de los vectores "first_track" y "second_track" son ambos uno, se imprime "YES" y se finaliza la ejecución.
            cout << "YES" << endl; 
            return 0;
        }
    }

    cout << "NO" << endl; // Si ninguna de las condiciones anteriores se cumple, se imprime "NO".
    return 0; 
}

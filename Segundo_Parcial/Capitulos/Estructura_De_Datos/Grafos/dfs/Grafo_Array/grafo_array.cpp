#include<bits/stdc++.h> 

#include<iostream> 

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

using namespace std; 

int main() { 
    input; // redirige la entrada estándar a un archivo llamado "in.txt"
    output; // redirige la salida estándar a un archivo llamado "out.txt"

    // Solicita al usuario el número de nodos en el grafo.
    int numNodos;
    cout << "Ingrese el número de nodos en el grafo: ";
    cin >> numNodos; // almacena el número de nodos en la variable "numNodos"

    // Crear una matriz de adyacencia para representar el grafo.
    int grafo[numNodos][numNodos]; // declara una matriz de adyacencia de tamaño "numNodos" x "numNodos"
    memset(grafo, 0, sizeof(grafo)); // inicializa todos los elementos de la matriz a cero

    // Solicita al usuario el número de aristas en el grafo.
    int numAristas;
    cout << "Ingrese el número de aristas en el grafo: ";
    cin >> numAristas; // almacena el número de aristas en la variable "numAristas"

    // Lee las aristas y actualizar la matriz de adyacencia.
    for (int i = 0; i < numAristas; i++) {
        int nodoOrigen, nodoDestino;
        cout << "Ingrese la arista " << i+1 << ": ";
        cin >> nodoOrigen >> nodoDestino; // almacena los nodos de la arista en las variables "nodoOrigen" y "nodoDestino"
        grafo[nodoOrigen][nodoDestino] = 1; // establece a 1 la posición correspondiente en la matriz de adyacencia para indicar una 
                                               arista dirigida desde "nodoOrigen" a "nodoDestino"
    }

    // Imprimir la matriz de adyacencia para visualizar el grafo.
    for (int i = 0; i < numNodos; i++) {
        for (int j = 0; j < numNodos; j++) {
            cout << "[" << grafo[i][j] << "]"; // imprime la posición correspondiente en la matriz de adyacencia
        }
        cout << endl; // imprime un salto de línea después de cada fila de la matriz
    }

    return 0; 
}

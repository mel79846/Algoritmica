#include<bits/stdc++.h> 

using namespace std; 

#define input freopen("in.txt","r",stdin) 
#define output freopen("out.txt","w",stdout) 

int main() { 
    input; // redirige la entrada estándar a un archivo llamado "in.txt"

    // Obtener el número de nodos del grafo.
    int numNodos;
    std::cin >> numNodos; // solicita al usuario el número de nodos y lo almacena en la variable "numNodos"

    vector<int> grafo[numNodos]; // crea una lista de adyacencia de tamaño "numNodos" para representar el grafo

    // Obtener el número de aristas del grafo.
    int numAristas;
    std::cin >> numAristas; // solicita al usuario el número de aristas y lo almacena en la variable "numAristas"

    // Leer las aristas e insertarlas en la lista de adyacencia.
    for (int i = 0; i < numAristas; i++) {
        int nodoOrigen, nodoDestino;
        std::cin >> nodoOrigen >> nodoDestino; // solicita al usuario las aristas y las almacena en las variables "nodoOrigen" y "nodoDestino"
        grafo[nodoOrigen].push_back(nodoDestino); // añade el nodo destino a la lista de adyacencia del nodo origen para representar una arista
    }

    // Imprimir la lista de adyacencia del grafo.
    for (int i = 0; i < numNodos; i++) {
        // Imprimir cada nodo conectado al nodo 'i'.
        for (int j = 0; j < grafo[i].size(); j++) {
            std::cout << "[" << grafo[i][j] << "]"; // imprime la posición correspondiente en la lista de adyacencia
        }
        std::cout << std::endl; // imprime un salto de línea después de cada fila de la matriz
    }

    return 0; 
}

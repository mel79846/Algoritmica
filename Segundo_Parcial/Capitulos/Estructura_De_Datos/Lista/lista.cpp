#include<bits/stdc++.h>

using namespace std; 

#define input freopen("in.txt","r",stdin) 
#define output freopen("out.txt","w",stdout) 

int main() { // comienza la función main
    input; // Abrir el archivo de entrada
    output; // Abrir el archivo de salida

    list<int> listita; // declara una lista llamada "listita" que almacenará enteros
    listita.push_back(1); // agrega el entero 1 al final de la lista
    listita.push_back(2); // agrega el entero 2 al final de la lista
    listita.push_back(3); // agrega el entero 3 al final de la lista

    list<int>::iterator it; // declara un iterador llamado "it" que puede utilizarse para recorrer la lista

    it = listita.end(); // establece el iterador al final de la lista
    cout << *it << endl; // imprime el valor al final de la lista, que debería ser el entero 3

    for (it = listita.begin(); it != listita.end(); it++) { // itera sobre cada elemento de la lista
        cout << *it << endl; // imprime el valor del elemento actual
    }

    return 0; // indica que el programa ha terminado de ejecutarse correctamente
}

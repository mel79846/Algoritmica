#include<bits/stdc++.h> 
using namespace std; 

int main() { 
    int array[10]; // declara un arreglo de 10 enteros llamado "array"
                   // (nota: no siempre se inicializa en cero)
    memset(array, 0, 10); // establece los primeros 10 bytes del arreglo en cero
    for(int i = 0; i< 10; i++) { // itera sobre cada elemento del arreglo
        array[i] = 0; // establece el valor de cada elemento en cero
    }
    // int array[]= new int[100] // esto no es válido en C++

    // lectura O(n) = 1 
    array[0]; // lee el valor del primer elemento del arreglo

    // escritura O(n) = 1
    array[0] = 10; // establece el valor del primer elemento del arreglo en 10

    return 0; // indica que el programa ha terminado de ejecutarse correctamente
}

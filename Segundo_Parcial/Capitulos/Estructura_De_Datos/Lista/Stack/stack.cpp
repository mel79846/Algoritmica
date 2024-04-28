#include<bits/stdc++.h> 
using namespace std; 

int main() { 
    stack<int> pilita; // declara una pila de enteros llamada "pilita"

    cout<<pilita.empty()<<endl; // imprime "1" si la pila está vacía, o "0" en caso contrario

    pilita.push(10); // agrega el entero 10 a la pila
    cout<<pilita.empty()<<endl; // imprime "0" si la pila no está vacía, o "1" en caso contrario
    cout<<pilita.top()<<endl; // imprime el valor del elemento en la cima de la pila (en este caso, 10)
    cout<<pilita.empty()<<endl; // imprime "0" si la pila no está vacía, o "1" en caso contrario
    cout<<pilita.pop()<<endl; // elimina y devuelve el valor del elemento en la cima de la pila (en este caso, 10)
    cout<<pilita.empty()<<endl; // imprime "1" si la pila está vacía, o "0" en caso contrario

    return 0; 
}

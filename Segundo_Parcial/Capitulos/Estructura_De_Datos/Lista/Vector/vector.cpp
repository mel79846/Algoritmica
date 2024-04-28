#include<bits/stdc++.h> 
using namespace std; 

int main() {
    vector<string> vectorcito(10, "Paul"); // declara un vector de cadenas de caracteres llamado "vectorcito" con una capacidad inicial de 10 elementos, 
    en este caso, cada uno inicializado con la cadena "Paul"

    vectorcito.push_back("Landaeta"); // agrega la cadena "Landaeta" al final del vector

    ["paul","paul","paul","paul","paul","paul","paul","paul","paul","paul","landaeta"]

    cout<<"tamaño del vector: "<< vectorcito.size()<<endl; // imprime el tamaño del vector (en este caso, 11)

    for(int i = 0 ; i < vectorcito.size() ; i++) { // itera sobre cada elemento del vector
    	cout<<i<<" "<< vectorcito[i]<<endl; // imprime el índice y el valor del elemento en el vector
    }

    return 0; 
}

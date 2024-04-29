#include <iostream> 
using namespace std; 

// Define una estructura "node" que contiene dos enteros "front" y "next".
typedef struct node {
    int front;
    int next;
} node;

int main() 
{
    int S, B; // Declara dos variables enteras "S" y "B".

    while (cin >> S >> B && (S + B) != 0) { // Este ciclo while se repite hasta que se haya leído un par de valores enteros válidos y la suma de estos sea distinta de cero.
        node a[S + 2]; // Crea un arreglo de estructuras "node" con un tamaño de "S + 2".

        for (int i = 1; i <= S; i++) { // Este ciclo for se repite "S" veces, una vez por cada elemento en el arreglo "a".
            a[i].front = i - 1; // Inicializa el valor de "front" para cada elemento en el arreglo "a".
            a[i].next = i + 1; // Inicializa el valor de "next" para cada elemento en el arreglo "a".
        }

        while (B--) { // Este ciclo while se repite "B" veces, una vez por cada par de enteros que se van a procesar.
            int x, y; // Declara dos variables enteras "x" y "y".
            scanf("%d%d", &x, &y); // Lee dos valores enteros desde la entrada estándar y los almacena en las variables "x" y "y".
            a[a[x].front].next = a[y].next; // Actualiza el valor de "next" para el elemento "x" en el arreglo "a".
            a[a[y].next].front = a[x].front; // Actualiza el valor de "front" para el elemento "y" en el arreglo "a".

            if (a[x].front == 0) // Verifica si "x" es el primer elemento en el arreglo "a".
                printf("*"); // Si lo es, imprime "*".
            else
                printf("%d", a[x].front); // De lo contrario, imprime el valor de "front" para el elemento "x" en el arreglo "a".
            printf(" "); // Imprime un espacio en blanco después de imprimir el valor de "front" para el elemento "x".
            if (a[y].next == S + 1) // Verifica si "y" es el último elemento en el arreglo "a".
                printf("*"); // Si lo es, imprime "*".
            else
                printf("%d", a[y].next); // De lo contrario, imprime el valor de "next" para el elemento "y" en el arreglo "a".
            printf("\n"); // Imprime un salto de línea después de imprimir los valores de "front" y "next" para los elementos "x" y "y".
        }
        cout << "-" << endl; // Imprime un guión y un salto de línea después de procesar todos los pares de enteros.
    }
    return 0; 
}

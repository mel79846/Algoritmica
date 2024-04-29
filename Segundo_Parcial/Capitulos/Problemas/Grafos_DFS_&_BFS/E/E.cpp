#include <iostream> 
#include <vector> 

using namespace std; 
// Declara un vector de cadenas para almacenar la grilla
vector<string> grafo;

// Declara dos arreglos para almacenar los desplazamientos en las direcciones x e y
int vx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int vy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

// Declara dos variables para almacenar el número de filas y columnas de la grilla
int filas, columnas;

// Función para realizar un recorrido en profundidad (DFS) en la grilla
void dfs(int fila, int columna)
{
    // Marca la celda actual como visitada (cambia el símbolo '#' por '.')
    grafo[fila][columna] = '.';

    // Itera sobre las 8 direcciones posibles
    for (int i = 0; i < 8; i++)
    {
        // Calcula las coordenadas de la celda adyacente
        int nuevaFila = fila + vx[i];
        int nuevaColumna = columna + vy[i];

        // Verifica si la celda adyacente está dentro de los límites de la grilla y si es un depósito de petróleo
        if (nuevaFila >= 0 && nuevaColumna >= 0 && nuevaFila < filas && nuevaColumna < columnas && grafo[nuevaFila][nuevaColumna] == '#')
        {
            // Realiza un recorrido en profundidad en la celda adyacente
            dfs(nuevaFila, nuevaColumna);
        }
    }
}

// Función para contar el número de depósitos de petróleo en la grilla
int countLoops()
{
    // Inicializa el contador de depósitos de petróleo en 0
    int amoebas = 0;

    // Itera sobre las filas de la grilla
    for (int i = 0; i < filas; i++)
    {
        // Itera sobre las columnas de la fila actual
        for (int j = 0; j < columnas; j++)
        {
            // Verifica si la celda actual es un depósito de petróleo
            if (grafo[i][j] == '#')
            {
                // Realiza un recorrido en profundidad en la celda actual
                dfs(i, j);

                // Incrementa el contador de depósitos de petróleo
                amoebas++;
            }
        }
    }

    // Retorna el número de depósitos de petróleo
    return amoebas;
}


int main(){
    // Lee el número de filas y columnas de la grilla
    cin >> filas >> columnas;

    // Redimensiona el vector de cadenas para almacenar la grilla
    grafo.resize(filas);

    // Itera sobre las filas de la grilla
    for (int i = 0; i < filas; i++)
    {
        // Lee la fila actual de la grilla
        cin >> grafo[i];
    }

    // Cuenta el número de depósitos de petróleo en la grilla
    int loops = countLoops();

    // Imprime el número de depósitos de petróleo
    cout << loops << endl;

    return 0;
}

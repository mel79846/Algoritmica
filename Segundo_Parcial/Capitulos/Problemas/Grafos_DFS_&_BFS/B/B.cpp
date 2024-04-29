#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; // Arreglo de enteros con desplazamientos en x
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1}; // Arreglo de enteros con desplazamientos en y

void dfs(int x, int y) { // Función recursiva que realiza un recorrido en profundidad
    grid[x][y] = '.'; // Establece el valor del elemento en la posición x, y a '.'

    for (int i = 0; i < 8; ++i) { // Ciclo for que se repite 8 veces, una vez por cada dirección
        int nx = x + dx[i]; // Calcula la coordenada nx
        int ny = y + dy[i]; // Calcula la coordenada ny

        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '@') { // Verifica si las coordenadas están dentro de los límites
                                                                                      y si el valor en la posición nx, ny es '@'
            dfs(nx, ny); // Realiza una llamada recursiva a la función dfs con las coordenadas nx, ny
        }
    }
}

int countOilDeposits() { // Función que cuenta cuántos depósitos de petróleo hay en la grilla
    int oilDeposits = 0; // Inicializa la variable que cuenta los depósitos de petróleo a 0
    for (int i = 0; i < rows; ++i) { // Ciclo for que se repite rows veces
        for (int j = 0; j < cols; ++j) { // Ciclo for que se repite cols veces
            if (grid[i][j] == '@') { // Verifica si el valor en la posición i, j es '@'
                dfs(i, j); // Realiza un recorrido en profundidad desde la posición i, j
                oilDeposits++; // Incrementa el contador de depósitos de petróleo
            }
        }
    }
    return oilDeposits; // Retorna el valor del contador de depósitos de petróleo
}

int main() { 
    while (cin >> rows >> cols && (rows != 0 && cols != 0)) { // Ciclo while que se repite siempre que se puedan leer dos números enteros rows 
                                                                 y cols de la entrada estándar y ambas variables no sean 0
        grid.resize(rows); // Establece el tamaño del vector grid a rows

        for (int i = 0; i < rows; ++i) { // Ciclo for que se repite rows veces
            cin >> grid[i]; // Lee una cadena de caracteres de la entrada estándar y la guarda en la posición i del vector grid
        }
        int oilDeposits = countOilDeposits(); // Llama a la función countOilDeposits y guarda el resultado en la variable oilDeposits
        cout << oilDeposits << endl; // Imprime el valor de oilDeposits en la salida estándar y agrega un salto de línea
    }
    return 0; 
}

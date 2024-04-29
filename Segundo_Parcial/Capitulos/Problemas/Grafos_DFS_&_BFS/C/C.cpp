#include <iostream>
#include <vector>

using namespace std;

int rows, cols;
vector<string> sky;

bool isValid(int x, int y) {
    // Verifica si las coordenadas x, y están dentro de los límites de la grilla
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

bool isStar(int x, int y) {
    // Verifica si la celda en la posición x, y es un depósito de petróleo ('*')
    if (sky[x][y] != '*') return false;
    
    // Itera sobre las posiciones adyacentes de la celda en la posición x, y
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            // Ignora la celda en la posición x, y (el propio depósito de petróleo)
            if (dx == 0 && dy == 0) continue;
            
            // Calcula las coordenadas de la celda adyacente
            int nx = x + dx, ny = y + dy;
            
            // Verifica si la celda adyacente es un depósito de petróleo ('*')
            if (isValid(nx, ny) && sky[nx][ny] == '*') return false;
        }
    }
    
    // Si ninguna de las celdas adyacentes es un depósito de petróleo, la celda en la posición x, y es un depósito de petróleo válido
    return true;
}

int countStars() {
    // Inicializa el contador de depósitos de petróleo
    int stars = 0;
    
    // Itera sobre las filas y columnas de la grilla
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Verifica si la celda en la posición i, j es un depósito de petróleo válido
            if (isStar(i, j)) stars++;
        }
    }
    
    // Retorna el contador de depósitos de petróleo
    return stars;
}

int main() {
    // Lee el número de filas y columnas de la grilla
    while (cin >> rows >> cols && (rows != 0 && cols != 0)) {
        // Lee la grilla
        sky.resize(rows);
        for (int i = 0; i < rows; ++i) {
            cin >> sky[i];
        }
        
        // Cuenta cuántos depósitos de petróleo hay en la grilla
        int stars = countStars();
        
        // Imprime el número de depósitos de petróleo en la salida estándar
        cout << stars << endl;
    }
    return 0;
}

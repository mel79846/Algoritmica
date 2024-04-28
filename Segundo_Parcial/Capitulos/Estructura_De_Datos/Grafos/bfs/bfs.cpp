#include<bits/stdc++.h> 

using namespace std; 

#define input freopen("in.txt","r",stdin)

#define output freopen("out.txt","w",stdout)

// declara un arreglo de booleanos llamado "vis" para marcar los nodos visitados
bool vis[10000]; 

// declara un vector de enteros llamado "grafo" para representar el grafo
vector<int> grafo[10000];

// declara un arreglo de enteros llamado "niveles" para almacenar el nivel de cada nodo
int niveles[10000];

// define la función BFS (Breadth-First Search)
void bfs (int nodoInicial) {
    // crea una cola de enteros llamada "colita"
    queue<int> colita;

    // agrega el nodo inicial a la cola
    colita.push(nodoInicial);

    // establece el nivel del nodo inicial a cero
    niveles[nodoInicial] = 0;

    // mientras la cola no esté vacía
    while(!colita.empty()){
        // obtiene el nodo actual de la cola
        int nodoActual = colita.front();

        // lo marca como visitado
        vis[nodoActual] = true;

        // itera sobre los vecinos del nodo actual
        for(int i = 0; i < grafo[nodoActual].size(); i++ ){
            int amigo = grafo[nodoActual][i]; // vecino o amigo

            // actualiza el nivel del vecino
            niveles[amigo] = niveles[nodoActual] + 1;

            // si el vecino no ha sido visitado
            if(!vis[amigo]) {
                // lo agrega a la cola
                colita.push(amigo);
            } 
        }
    }
}

int main() {
    // abre los archivos de entrada y salida
    input;
    output;

    // lee el número de nodos y aristas
    int nodos, aristas;
    cin>>nodos>>aristas; // 11 19

    // inicializa el arreglo de visitados a falso
    fill(vis, vis+10000, false);

    // lee las aristas y las agrega al grafo
    for(int i = 0 ; i < aristas; i++ ) {
        int nodoInicial, nodoFinal;
        cin>>nodoInicial>>nodoFinal;
        grafo[nodoInicial].push_back(nodoFinal);
        grafo[nodoFinal].push_back(nodoInicial); // agrega la arista en ambas direcciones
    }

    // si el nodo S puede llegar al nodo T
    int S,T; // 1 7
    cin>>S>>T;

    // llama a la función BFS con el nodo S
    bfs(S);

    // si el nodo T ha sido visitado
    if(vis[T]) {
        // imprime "Si lo podría conocer"
        cout<<"Si lo podria conocer"<<endl;
    } else {
        // de lo contrario, imprime "No lo podría conocer"
        cout<<"No lo podria conocer"<<endl;
    }

    // cierra los archivos de entrada y salida
    fclose(stdin);
    fclose(stdout);

    return 0;
}

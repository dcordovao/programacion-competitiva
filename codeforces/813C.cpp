#include <cstdio>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph
{
public:
    int numVertices;
    vector <vector<int> > adjList;
    Graph(int N);
    void addEdge(int src, int dest);
};

Graph::Graph(int N) {
    numVertices = N;
    adjList = vector<vector<int> >(N, vector<int>(0));
}

void Graph::addEdge(int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

int solve(Graph graph, int origen2) {

    // Primer BFS
    int origen1 = 0, *distancia1;
    bool *estado1; // True si se visito
    estado1 = new bool[graph.numVertices];
    distancia1 = new int[graph.numVertices];

    for (int i = 0; i < graph.numVertices; i++) {
        estado1[i] = false;
        distancia1[i] = numeric_limits<int>::max(); // Infinito
    }

    distancia1[origen1] = 0;
    estado1[origen1] = true;
    queue < int> cola;
    cola.push(origen1);
    while (!cola.empty()) {
        int nodo;
        nodo = cola.front();
        cola.pop();
        for (int i = 0; i < graph.adjList[nodo].size(); i++) {
            int nodo2;
            nodo2 = graph.adjList[nodo][i];
            if (estado1[nodo2] == false) {
                estado1[nodo2] = true;
                distancia1[nodo2] = distancia1[nodo] + 1;
                cola.push(nodo2);
            }
        }
    }
    /*
    printf("Distancias Alice: \n");
    for (int i = 0; i< graph.numVertices; i++) {
        printf("%d: %d\n", i+1, distancia1[i]);
    } */

    //Segundo BFS

    int *distancia2;
    bool *estado2; // True si se visito
    estado2 = new bool[graph.numVertices];
    distancia2 = new int[graph.numVertices];

    for (int i = 0; i < graph.numVertices; i++) {
        estado2[i] = false;
        distancia2[i] = numeric_limits<int>::max(); // Infinito
    }

    int max = distancia1[origen2];
    int nodomax = origen2;
    distancia2[origen2] = 0;
    estado2[origen2] = true;
    cola.push(origen2);
    while (!cola.empty()) {
        int nodo;
        nodo = cola.front();
        cola.pop();
        for (int i = 0; i < graph.adjList[nodo].size(); i++) {
            int nodo2;
            nodo2 = graph.adjList[nodo][i];
            if (estado2[nodo2] == false and
                distancia1[nodo2]>distancia2[nodo]+1) {
                estado2[nodo2] = true;
                distancia2[nodo2] = distancia2[nodo] + 1;
                if (distancia1[nodo2] > max) {
                    max = distancia1[nodo2];
                    nodomax = nodo2;
                }
                cola.push(nodo2);
            }
        }
    }
    /*
    printf("Distancias Bob: \n");
    for (int i = 0; i< graph.numVertices; i++) {
        if (distancia2[i] == numeric_limits<int>::max()) {
            printf("%d: Infinito\n", i+1);
        } else {
            printf("%d: %d\n", i+1, distancia2[i]);
        }
    } */

    return distancia1[nodomax];
}

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    Graph graph =  Graph(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph.addEdge(a-1, b-1);
    }

    printf("%d\n",solve(graph, x-1)*2);

  return 0;
}

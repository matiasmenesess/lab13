//Integrantes:
//1. Olivares Sarmiento, Javier Ignacio Leon
//2. Silva Reyes, Santiago Miguel
//3. Meneses Roncal, Matias Alonso

#include <vector>
#include <limits>

using namespace std;

template<typename T>
class Heap {
    string type;
    vector<T> elements;

    void heapify_down(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (type == "MAX_HEAP") {
            if (left < elements.size() && elements[left] > elements[largest]) {
                largest = left;
            }
            if (right < elements.size() && elements[right] > elements[largest]) {
                largest = right;
            }
        } else if (type == "MIN_HEAP") {
            if (left < elements.size() && elements[left] < elements[largest]) {
                largest = left;
            }
            if (right < elements.size() && elements[right] < elements[largest]) {
                largest = right;
            }
        }

        if (largest != i) {
            swap(elements[i], elements[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(int i) {
        int parent = (i - 1) / 2;
        if (i && ((type == "MAX_HEAP" && elements[i] > elements[parent]) ||
                  (type == "MIN_HEAP" && elements[i] < elements[parent]))) {
            swap(elements[i], elements[parent]);
            heapify_up(parent);
        }
    }

public:
    Heap(string heapType) : type(heapType) {}

    void insert(T val) {
        elements.push_back(val);
        heapify_up(elements.size() - 1);
    }

    void pop() {
        if (elements.size() == 0) {
            return;
        }
        swap(elements[0], elements[elements.size() - 1]);
        elements.pop_back();
        heapify_down(0);
    }

    T top() {
        if (elements.size() == 0) {
            throw out_of_range("Heap vacio");
        }
        return elements[0];
    }

    int size() {
        return elements.size();
    }
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        
        // Construimos la lista de adyacencia
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].emplace_back(v, time);
            adj[v].emplace_back(u, time);
        }

        // Distancias mínimas inicializadas a infinito y formas de llegar
        vector<long long> dist(n, LLONG_MAX);
        vector<int> caminos(n, 0);
        dist[0] = 0;
        caminos[0] = 1;

        // Usamos el Heap personalizado como min-heap
        Heap<pair<long long, int>> minHeap("MIN_HEAP");
        minHeap.insert({0, 0}); // (distancia, nodo de origen)

        while (minHeap.size() > 0) {
            auto [curDist, u] = minHeap.top();
            minHeap.pop();

            // Ignoramos si encontramos una distancia más larga de lo necesario
            if (curDist > dist[u]) continue;

            for (auto& [v, time] : adj[u]) {
                long long newDist = curDist + time;

                // Si encontramos un camino más corto
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    caminos[v] = caminos[u];
                    minHeap.insert({newDist, v});
                }
                // Si encontramos otro camino de igual longitud mínima
                else if (newDist == dist[v]) {
                    caminos[v] = (caminos[v] + caminos[u]) % MOD;
                }
            }
        }

        return caminos[n - 1];
    }
};

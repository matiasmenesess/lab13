//Integrantes:
//1. Olivares Sarmiento, Javier Ignacio Leon
//2. Silva Reyes, Santiago Miguel
//3. Meneses Roncal, Matias Alonso

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> V(n, 0.0);  
        V[start] = 1.0; 

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];
                //RELAJACION
                if (V[u] * prob > V[v]) {
                    V[v] = V[u] * prob;
                }
                if (V[v] * prob > V[u]) {
                    V[u] = V[v] * prob;
                }
            }

        }

        if (V[end] > 0.0) { 
            return V[end];  
        } else {
            return 0.0;  
        }

    }
};

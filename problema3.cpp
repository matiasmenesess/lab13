//Integrantes:
//1. Olivares Sarmiento, Javier Ignacio Leon
//2. Silva Reyes, Santiago Miguel
//3. Meneses Roncal, Matias Alonso

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {


        vector<double> V(n, 0);  
        V[start] = 1; 


        for (int i = 0; i <= n - 2; i++ ){
            int FactAct = 0; 
            for (int j = 0; j < edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];

                double probabilidad = succProb[j];

                //relax (parte de bellman ford)
                if (V[u] * probabilidad > V[v]){
                    FactAct=1;
                    V[v] = V[u] * probabilidad;
                }

                if (V[v] * probabilidad > V[u]){
                    FactAct=1;
                    V[u] = V[v] * probabilidad;
                }
            }

            if(FactAct==0){
                break;
            }

        }

        if (V[end] > 0) { 
            return V[end];  
        } 
        else{
            return 0;  
        }

    }
};

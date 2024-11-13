

//Integrantes:
//1. Olivares Sarmiento, Javier Ignacio Leon
//2. Silva Reyes, Santiago Miguel
//3. Meneses Roncal, Matias Alonso

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool En(int valor, vector<int> V){

    for(int i = 0; i <= V.size(); i++){
        if (valor == V[i]){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> G;

        for(int i = 0; i < n; i++)
        {
            vector<int> L;
            G[i] = L;
        }

        for(int i = 1; i <= n; i++) 
        {
            G[i - 1].push_back(i);
        }


        for(auto e: dislikes)
        {
            for(int i = 0; i<n; i++)
            {
                if (En(e[0],G[i]) and En(e[1],G[i]))
                {
                    G[i+1].push_back((e[1]));
                    remove(G[i].begin(), G[i].end(),e[1]);
                }
            }
        }

        int contador=0;
        
        for(int i = 0; i <= G.size(); i++)
        {
            contador++;
        }

        if(contador >= 2)
        {
            return false;
        }
        return true;

    }
};

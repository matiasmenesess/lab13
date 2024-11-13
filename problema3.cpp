//Integrantes:
//1. Olivares Sarmiento, Javier Ignacio Leon
//2. Silva Reyes, Santiago Miguel
//3. Meneses Roncal, Matias Alonso
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// bool En(int valor, vector<int>& V){
//     for(auto E: V){
//         if (valor == E){
//             return true;
//         }
//     }
//     return false;
// }

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int contador=1;
      //  vector<vector<int>> G;
       // for(auto e: isConnected){
            int i=1;
            //for(auto a: e){
               // if(e[i-1] == 1){
                  //  if(!En(i,G[0]))
                        //G[0].push_back(i);
                //}
                //contador++;
                i++;
            //}
        //}
        return contador;
    }
};

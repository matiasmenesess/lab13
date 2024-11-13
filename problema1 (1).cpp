
//Integrantes:
//1. Olivares Sarmiento, Javier Ignacio Leon
//2. Silva Reyes, Santiago Miguel
//3. Meneses Roncal, Matias Alonso
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1){
            return true;
        }
        for(auto e: edges){
            if((e[0]== source && e[1]== destination) or (e[0]== destination && e[1]== source))
                return true;
        }
        return false;
    }
};

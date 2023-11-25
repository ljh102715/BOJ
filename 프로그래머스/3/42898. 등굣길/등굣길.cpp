#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<long long>> worlds(n+1, vector<long long> (m+1, 0));
    for(int i = 0; i < puddles.size(); i++)
        worlds[puddles[i][1]][puddles[i][0]] = -1;
    for(int i = 0; i <= n; i++){
        worlds[i][0] = -1;
    }
    for(int i = 0; i <= m; i++){
        worlds[0][i] = -1;
    }
    worlds[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(worlds[i][j] == -1) continue;
            long long upper = worlds[i-1][j];
            long long left = worlds[i][j-1];
            if(upper != -1 && left != -1)
                worlds[i][j] = upper + left;
            else if(upper != -1)
                worlds[i][j] = upper;
            else if(left != -1)
                worlds[i][j] = left;
            worlds[i][j] %= 1000000007;
        }
    }
    
    return worlds[n][m];
}
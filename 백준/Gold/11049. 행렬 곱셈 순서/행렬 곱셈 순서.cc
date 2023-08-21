#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num;
    int matrices[2][501];
    int dp[501][501] = {0,};
    cin >> num;
    for(int i = 1; i <= num; i++)
        cin >> matrices[0][i] >> matrices[1][i];
    
    
	for(int i = 1; i <= num; i++){
        for(int row = 1; row <= num - i; row++){
            int col = i + row;
            if(row == col){dp[row][col] = 0; continue;}
            dp[row][col] = 999999999;

            for(int k = row; k < col; k++){
                dp[row][col] = min(dp[row][col], dp[row][k] + dp[k+1][col] + matrices[0][row] * matrices[1][k] * matrices[1][col]);
            }
        }
    }

	cout << dp[1][num];


 
}
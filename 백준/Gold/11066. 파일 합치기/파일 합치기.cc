#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;
int one, zero, minus_one;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int num, arr[501], sum[501] = {0,}, dp[501][501] = {0,};
        cin >> num;

        for(int j = 1; j <= num; j++){
            cin >> arr[j];
            sum[j] = sum[j-1] + arr[j];
        }
        
        for(int j = 1; j <= num; j++){
            for(int row = 1; row <= num - j; row++){
                int col = row + j;
                if(row == col){dp[row][col] = 0; continue;}
                else if(col == row + 1){
                    dp[row][col] = arr[row] + arr[col];
                }
                else{   
                    dp[row][col] = 999999999;
                
                    for(int l = row; l <= col; l++){
                        dp[row][col] = min(dp[row][col], dp[row][l] + dp[l+1][col] + sum[col] - sum[row-1]);
                    }
                }
            }
        }
        cout << dp[1][num] << "\n";
    }
}
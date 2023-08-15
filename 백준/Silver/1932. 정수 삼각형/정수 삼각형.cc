#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    int num, arr[501][501], dp[501][501] = {0,};
    cin >> num;
    for(int i = 1; i <= num; i++)
        for(int j = 1; j <= i; j++)
            cin >> arr[i][j];

    dp[1][1] = arr[1][1];
    for(int i = 2; i <= num; i++)
        for(int j = 1; j <= i; j++){
            if(j == 1)
                dp[i][j] = dp[i-1][j] + arr[i][j];
            else if(j == i)
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            else   
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }

    int max = dp[num][1];
    for(int i = 2; i <= num; i++)
        if(max < dp[num][i]){
            max = dp[num][i];
        }
    cout << max;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    
    int num, dp[501][501] = {0,};
    cin >> num;
    for(int i = 1; i <= num; i++)
        for(int j = 1; j <= i; j++)
            cin >> dp[i][j];

    for(int i = num-1; i >=1; i--)
        for(int j = 1; j <= i; j++){
            dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
        }
    cout << dp[1][1];
}
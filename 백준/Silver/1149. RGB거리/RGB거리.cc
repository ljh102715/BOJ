#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num, cost[3][1001];//0 : red, 1 : green, 2 : blue
    int dp[3][1001] = {0,};
    cin >> num;
    for(int i = 1; i <= num; i++)
        for(int j = 0; j < 3; j++)
            cin >> cost[j][i];

    dp[0][1] = cost[0][1], dp[1][1] = cost[1][1], dp[2][1] = cost[2][1];

    for(int i = 2; i <= num; i++)
        for(int j = 0; j < 3; j++){
            if(j == 0)
                dp[j][i] = min(dp[1][i-1], dp[2][i-1]) + cost[0][i];
            else if(j == 1)
                dp[j][i] += min(dp[0][i-1], dp[2][i-1]) + cost[1][i];
            else
                dp[j][i] += min(dp[0][i-1], dp[1][i-1]) + cost[2][i];
        }
    int temp = min(dp[0][num], dp[1][num]);
    cout << min(temp, dp[2][num]);
}
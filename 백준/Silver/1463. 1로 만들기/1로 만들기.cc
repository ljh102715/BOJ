#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num, dp[1000001] = {0,};
    cin >> num;

    dp[1] = 0, dp[2] = 1, dp[3] = 1;

    for(int i = 4; i <= num; i++){
        if(i%3 == 0 && i % 2 == 0){
            int temp = min(dp[i/3], dp[i/2]);
            dp[i] = min(temp, dp[i-1]) + 1;
        }else if(i % 3 == 0){
            dp[i] = min(dp[i/3], dp[i-1]) + 1;
        }else if(i%2 == 0){
            dp[i] = min(dp[i/2], dp[i-1]) + 1;
        }else{
            dp[i] = dp[i-1] + 1;
        }
    }
    
    cout << dp[num];
}
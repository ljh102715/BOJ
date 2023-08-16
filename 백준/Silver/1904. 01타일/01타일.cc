#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    long long dp[1000001] = {0,1,2};
    int num;
    cin >> num;
    if(num < 3){cout << dp[num]; return 0;}
    for(int i = 3; i <= num; i++)  
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    
    cout << dp[num];
}
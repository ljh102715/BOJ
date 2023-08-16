#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
long long dp[101] = {0,1,1,1,2,2,};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int tc, num;
    cin >> tc;

    for(int i = 6; i <= 100; i++)
        dp[i] = dp[i-1] + dp[i-5];

    for(int i = 0; i < tc; i++){
        cin >> num;
        cout << dp[num] << endl;
    }
}
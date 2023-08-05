#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, dp[1001];
	cin >> num;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i<= num; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % 10007;
	}
	cout << dp[num];
}

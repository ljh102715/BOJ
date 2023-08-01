#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main(void) {

	int num;
	long long dp[31][31] = { 0,};
	dp[0][0] = 1, dp[1][0] = 1, dp[1][1] = 1;
	cin >> num; 

	for (int i = 1; i <= 30; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) dp[i][0] = 1;
			else if (j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
		}

	while(num--){
		int west, east;
		cin >> west >> east;
		cout << dp[east][west] << "\n";
	}

}
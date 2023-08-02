#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int num, bag, dp[101][100001] = {0,};
int item[2][101];

int main(void) {

	cin >> num >> bag;
	for(int i = 1; i <= num; i++)
		cin >> item[0][i] >> item[1][i];//0은 무게, 1은 가치

	for(int i = 1; i <= num; i++){
		for(int j = 1; j <= bag; j++){
			if(j >= item[0][i])
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - item[0][i]] + item[1][i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[num][bag];
}
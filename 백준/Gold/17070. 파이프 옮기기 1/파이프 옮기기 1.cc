#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int num, house[17][17], dp[17][17][3] = {0,};
	cin >> num;
	for(int i = 1; i<=num; i++){
		for(int j = 1; j<=num; j++)
			cin >> house[i][j];
	}

	dp[1][2][0] = 1;
	for(int i = 1; i <= num; i++){
		for(int j = 2; j <= num; j++){
			if(i == 1 && j == 2) continue;
			if(house[i][j] == 1) {
				dp[i][j][0] = 0;
				dp[i][j][1] = 0;
				dp[i][j][2] = 0;
			}
			else{
				for(int k = 0; k < 3; k++){
					if(k == 0){
						dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
					}
					else if(k == 1){
						dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
					}
					else{
						if(house[i-1][j] != 1 && house[i][j-1] != 1)
							dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
					}
				}
			}
		}
	}
	cout << dp[num][num][0] + dp[num][num][1] + dp[num][num][2];
}
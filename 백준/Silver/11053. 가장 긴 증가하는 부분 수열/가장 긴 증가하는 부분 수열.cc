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
	
	int num, max = 0;
	int arr[1001], dp[1001] = {0,};
	cin >> num;
	for(int i = 1; i <= num; i++)
		cin >> arr[i];

	for(int i = 1; i <= num; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;

			if(max < dp[i])
				max = dp[i];
		}
	}

	cout << max;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num, temp, max, dp[100001] = {0,};
    cin >> num;
    for(int i = 1; i <= num; i++)
        cin >> dp[i];
    
    max = dp[1], temp = dp[1];
    for(int i = 2; i <= num; i++){
        if(temp < 0)
            temp = 0;
        
        temp += dp[i];
        if(max < temp)
            max = temp;
    }
    cout << max;
}
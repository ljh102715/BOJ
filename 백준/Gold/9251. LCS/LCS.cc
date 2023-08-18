#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    int len_a = a.size(), len_b = b.size();
    int dp[1001][1001] = {0,};

    for(int i = 1; i <= len_a; i++)
        for(int j = 1; j <= len_b; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else   
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    
    cout << dp[len_a][len_b];

}

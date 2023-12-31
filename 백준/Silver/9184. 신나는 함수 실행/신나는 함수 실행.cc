#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int solve(int a, int b, int c);
int dp[21][21][21] = {0,};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    while(1){
    cin >> a >> b >> c;
    if(a == -1 && b == -1 && c == -1)
        break;

    cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << "\n";
    }

}
int solve(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    
    if(a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);
    
    if(dp[a][b][c])
        return dp[a][b][c];

    if(a < b && b < c){
        dp[a][b][c] = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
        return dp[a][b][c];
    }
    
    dp[a][b][c] = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
    return dp[a][b][c];
}
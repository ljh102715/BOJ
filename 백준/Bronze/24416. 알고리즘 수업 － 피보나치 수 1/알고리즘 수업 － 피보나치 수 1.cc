#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int rFibonacci(int num);
void dpFibonacci(int num);
int rCnt = 0, dpCnt = 0, dp[41] = {0,};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num;
    cin >> num;
    rFibonacci(num);
    dpFibonacci(num);
    cout << rCnt << " " << dpCnt;


}
int rFibonacci(int num){
    if(num == 1 || num == 2){rCnt++; return 1;}
    return rFibonacci(num-1) + rFibonacci(num-2);
}
void dpFibonacci(int num){
    dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= num; i++){
        dpCnt++;
        dp[i] = dp[i-1] + dp[i-2];
    }
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int bi(int N, int K);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    cout << bi(N, K);
    return 0;
}
int bi(int N, int K){
    if(N < K) return 0;

    if(K == 0 || N == K)
        return 1;
    
    return bi(N-1, K) + bi(N-1, K-1);
}
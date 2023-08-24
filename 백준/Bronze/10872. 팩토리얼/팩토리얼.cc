#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int fact(int N);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    cout << fact(N);
    return 0;
}
int fact(int N){
    if(N <= 1) return 1;

    return fact(N-1) * N;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    cout << (N-1) * N;
    return 0;
}
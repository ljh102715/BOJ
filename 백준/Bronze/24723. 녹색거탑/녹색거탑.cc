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
    
    int N, option = 2, ans = 1;
    cin >> N;

    while(N--){
        ans *= option;
    }
    cout << ans;
    
}
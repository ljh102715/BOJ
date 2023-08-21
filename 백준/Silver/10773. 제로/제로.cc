#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    stack<int> stack;
    int cnt, num, sum = 0, size;
    cin >> cnt;
    for(int i = 0; i < cnt; i++){
        cin >> num;
        if(num) stack.push(num);
        else stack.pop();
    }
    size = stack.size();
    for(int i = 0; i < size; i++){
        sum += stack.top();
        stack.pop();
    }
    cout << sum;
}
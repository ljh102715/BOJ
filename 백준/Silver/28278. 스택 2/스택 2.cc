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
    int num, order, order_one;
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> order;
        switch(order){
            case 1:
                cin >> order_one;
                stack.push(order_one);
                break;
            case 2:
                if(stack.empty()) cout << "-1\n";
                else {cout << stack.top() << "\n"; stack.pop();}
                break;
            case 3:
                cout << stack.size() << "\n";
                break;
            case 4:
                if(stack.empty()) cout << "1\n";
                else cout << "0\n";
                break;
            case 5:
                if(stack.empty()) cout << "-1\n";
                else{
                    cout << stack.top() << "\n";
                }
                break;
        }
    }
}
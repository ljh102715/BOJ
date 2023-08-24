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
    
    queue<int> que;
    int num, temp;
    cin >> num;
    while(num--){
        string order;
        cin >> order;

        if(order == "push"){
            cin >> temp;
            que.push(temp);
        }else if(order == "pop"){
            if(que.empty()){
                cout << "-1\n";
            }else{
                cout << que.front() << "\n";
                que.pop();
            }
        }else if(order == "size"){
            cout << que.size() << "\n";
        }else if(order == "empty"){
            if(!que.empty())
                cout << "0\n";
            else
                cout << "1\n";
        }else if(order == "front"){
            if(que.empty())
                cout << "-1\n";
            else
                cout << que.front() << "\n";
        }else if(order == "back"){
            if(que.empty())
                cout << "-1\n";
            else
                cout << que.back() << "\n";
        }
    }

}
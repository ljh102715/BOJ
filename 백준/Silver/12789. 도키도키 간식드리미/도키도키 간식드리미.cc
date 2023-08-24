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
    
    int num, temp, turn = 1;
    bool ifCan = true;
    cin >> num;

    queue<int> line;
    stack<int> extra;
    vector<int> result;

    for(int i = 0 ; i < num; i++){
        cin >> temp;
        line.push(temp);
    }

    while(!line.empty()){
        if(line.front() == turn){
            result.push_back(turn);
            line.pop();
            turn++;
        }
        else if(!extra.empty() && extra.top() == turn){
            result.push_back(turn);
            extra.pop();
            turn++;
        }
        else{
            extra.push(line.front());
            line.pop();
        }
    }
    while(!extra.empty()){
        result.push_back(extra.top());
        extra.pop();
    }
    
    for(int i = 1; i <= num; i++){
        if(result[i-1] != i){
            ifCan = false;
            break;
        }
    }
    if(ifCan)
        cout << "Nice";
    else
        cout << "Sad";

}
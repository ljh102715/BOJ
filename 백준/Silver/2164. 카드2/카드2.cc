#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int num;
    cin >> num;

    for(int i = 1; i <= num; i++)
        q.push(i);
    
    while(q.size() >= 2){
        q.pop();
        int up = q.front();
        q.pop();
        q.push(up);
    }
    cout << q.front();
}
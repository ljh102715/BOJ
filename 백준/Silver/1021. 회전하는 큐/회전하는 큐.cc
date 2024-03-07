#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int max, cnt, answer = 0;
    cin >> max >> cnt;

    for(int i = 1; i <= max; i++)
        dq.push_back(i);

    while(cnt--){
        int temp;
        cin >> temp;

        int pos = 0;
        for(deque<int>::iterator it = dq.begin(); it != dq.end(); it++){
            if(dq[pos] == temp)
                break;
            pos++;
        }
        if(dq.size() / 2 < pos){
            int temp_cnt = dq.size() - pos;
            while(temp_cnt--){
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
                answer++;
            }
        }else if(pos != 0){
            while(pos--){
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
                answer++;
            }
        }
        dq.pop_front();
    }
    cout << answer;

}
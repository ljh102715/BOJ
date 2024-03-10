#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, answer = 0;
    cin >> num;

    while(num--){

        string input;
        stack<char> st;
        cin >> input;
        if(input.length() % 2) //길이 홀수면 X
            continue;

        for(int i = 0; i < input.length(); i++){
            if(!st.empty() && st.top() == input[i]){
                st.pop();
            }else{
                st.push(input[i]);
            }
        }

        if(st.empty())
            answer++;
    }
    cout << answer;
}
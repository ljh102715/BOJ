#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    //안정적인지 검사
    //가능한 연산 -> 각 괄호를 다른 괄호로 변경할 수 있다.
    //input에 대해서 안정적으로 만들기 위해 필요한 최소 연산의 수를 구해라.
    vector<int> answer;

    while(1){
        int cnt = 0;
        string input;
        stack<char> st;
        cin >> input;

        if(input[0] == '-')
            break;

        string temp = "";

        for(auto c : input){
                
            if(c == '{'){
                st.push(c);
            }else{
                if(c == '}'){
                    if(!st.empty() && st.top() == '{')
                        st.pop();
                    else
                        st.push('}');
                }
            }

        }
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        for(int i = 0; i < temp.length(); i++){
            if(i % 2){
                if(temp[i] == '{')
                    cnt++;
            }else{
                if(temp[i] == '}')
                    cnt++;
            }
        }
        answer.push_back(cnt);
    }

    for(int i = 0; i < answer.size(); i++)
        cout << i+1 << ". " << answer[i] << "\n";
}
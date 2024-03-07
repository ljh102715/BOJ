#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string input;
        getline(cin, input);
        if(input == ".")
            break;
        stack<char> st;
        bool check = true;
        for(auto c : input){
            if(c == '(' || c == '['){
                st.push(c);
            }else if(c == ')'){
                if(st.empty()){
                    check = false;
                    break;
                }
                if(st.top() != '('){
                    check = false;\
                    break;
                }
                st.pop();
            }else if(c == ']'){
                if(st.empty()){
                    check = false;
                    break;
                }
                if(st.top() != '['){
                    check = false;
                    break;
                }
                st.pop();
            }
        }
        if(check && st.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    

}
#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //레이저는 ()의 모양을 갖는다.
    //막대는 항상 짧은게 위에 있다. -> 스택을 사용할 수 있는 이유
    //많은 괄호들 중에 레이저를 구분해주어야 한다 -> 어떻게? 이전 상태를 저장해야할까?
    //레이저가 나오면 스택에 쌓인 (의 갯수, 즉 지금 아래있는 막대의 갯수를 더해주어야 한다.

    string input;
    stack<char> st;
    int answer = 0;
    char before;

    cin >> input;

    for(int i = 0; i < input.length(); i++){ 
        if(i != 0)
            before = input[i-1];

        if(input[i] == '(') //여는 괄호일 때, stack에 넣어준다.
            st.push(input[i]);
        else{ //닫는 괄호일 때, 레이저인지 검사.
            if(before == '('){ //레이저일 때 -> 잘리는 막대 수 계산
                st.pop();
                answer += st.size();
            }
            else{              //레이저가 아닐 때 -> stack pop
                answer++;      // ! 마지막은 레이저가 없더라도 잘린 수를 한번 더 더해주어야 한다.
                st.pop();
            }
        }
    }

    cout << answer;

    return 0;
}
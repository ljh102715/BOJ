#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> st;
    int cnt;
    long long answer = 0;
    cin >> cnt;
    st.push(1000000001);
    while(cnt--){
        int height;
        cin >> height;
    
        while(st.top() <= height)
            st.pop();

        answer += st.size() - 1;
        st.push(height);
    }

    cout << answer;
}
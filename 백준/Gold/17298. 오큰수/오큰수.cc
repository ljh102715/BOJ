#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, pos = 0;
    cin >> num;

    vector<int> v(num, 0);
    stack<pair<int, int>> st;

    for(int i = 0; i < num; i++){
        int temp;
        cin >> temp;
        while(!st.empty() && st.top().first < temp){
            pair<int, int> t = st.top();
            st.pop();
            v[t.second] = temp;
        }
        st.push(make_pair(temp, i));
    }

    while(!st.empty()){
        pair<int, int> t = st.top();
        st.pop();
        v[t.second] = -1;
    }
    for(auto i : v)
        cout << i << " ";
}
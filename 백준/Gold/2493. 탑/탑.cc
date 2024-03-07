#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> st;

    int cnt;
    cin >> cnt;

    vector<int> v(cnt+1, 0);

    for(int i = 1; i <= cnt; i++){
        int num;
        cin >> num;
        if (st.empty()){
            st.push(make_pair(i, num));
        }else if(st.top().second <= num){//크거나 같은거 들어오면
            while(!st.empty() && st.top().second <= num)
                st.pop();
            
            if(!st.empty())
                v[i] = st.top().first;
            st.push(make_pair(i, num));
        
        }else{//작은거 들어오면
            pair<int,int> t = st.top();
            v[i] = t.first;
            st.push(make_pair(i, num));
        }

    }

    for(int i = 1; i <= cnt; i++)
        cout << v[i] << " ";
    
}
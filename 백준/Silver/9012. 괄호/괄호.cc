#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num, cnt;
    bool ifVPS = true;
    cin >> num;

    for(int i = 0; i < num; i++){
        cnt = 0;
        string a;
        cin >> a;
        for(int j = 0; j < a.size(); j++){
            if(a[j] == '(')
                cnt++;
            else
                cnt--;
            if(cnt < 0){
                ifVPS = false;
                break;
            }
        }
        if(cnt==0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
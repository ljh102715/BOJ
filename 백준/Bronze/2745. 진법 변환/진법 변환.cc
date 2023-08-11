#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string num;
    int numeral, ans = 0, temp, cnt = 0;
    cin >> num >> numeral;
    for(int i = num.length()-1; i>=0; i--){
        if(num[i] >= '0' && num[i] <= '9'){
            temp = num[i] - '0';
        }else{
            temp = num[i] + 10 - 'A';
        }
        ans += temp * (int)pow(numeral, cnt);
        cnt++;
    }

    cout << ans;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

void recur(string &a, int start, int length);
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num, value, arr[10], cnt = 0;
	cin >> num >> value;
	for(int i = 0; i < num; i++)
		cin >> arr[i];

	for(int i = num-1; i>=0; i--){
		if(value >= arr[i]){
			cnt += value / arr[i];
			value %= arr[i];
		}else{
			continue;
		}
	}

	cout << cnt;
}
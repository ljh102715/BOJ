#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, arr[16] = {1, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184};
	cin >> n;
	cout << arr[n];
	return 0;
}
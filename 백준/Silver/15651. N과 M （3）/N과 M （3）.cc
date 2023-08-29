#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, cnt;
vector<int> arr;
void recur();
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	recur();

	return 0;
}
void recur(){
	if(cnt == m){
		for(int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for(int i = 1; i <= n; i++){
		arr.push_back(i);
		cnt++;
		recur();
		cnt--;
		arr.pop_back();
	}
}
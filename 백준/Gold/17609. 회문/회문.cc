#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string a;
int recur(int left, int right, int cnt);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;
	for(int k = 0; k < num; k++){
		cin >> a;
		cout << recur(0, a.length()-1, 0) << "\n";
	}

}
int recur(int left, int right, int cnt){
	while(left < right){
		if(a[left] == a[right]){
			left += 1;
			right -= 1;
		}else{
			if(cnt == 0){
				if(recur(left+1, right, cnt+1) == 0 || recur(left, right - 1, cnt + 1) == 0) return 1;
			}
			return 2;
		}
	}
	return 0;
}
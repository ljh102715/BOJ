#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string a = "";
int recur(int left, int right, int cnt);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;
	string a = "", answer = "";
	for(int k = 0; k < num; k++){
		char temp;
		cin >> temp;
		a += temp;
	}

	int left = 0, right = a.length() - 1, left_temp, right_temp;
	while(left < right){

		//cout << left << " " << right << " " << answer << "\n"; 
		if(a[left] < a[right]){
			answer += a[left];
			left++;
		}else if(a[left] > a[right]){
			answer += a[right];
			right--;
		}else{
			left_temp = left;
			right_temp = right;
			while(left_temp < right_temp){

				if(a[left_temp] > a[right_temp]){
					answer += a[right];
					right--;
					break;
				}else if(a[left_temp] < a[right_temp]){
					answer += a[left];
					left++;
					break;
				}else{
					left_temp++;
					right_temp--;
				}
			}
			if(left_temp >= right_temp){
				while(left < right){
					answer += a[left];
					answer += a[right];
					left++;
					right--;
				}
			}
		}
		if(left == right)
			answer += a[left];
	}
	for(int i = 0; i < answer.length(); i++){
		if(i % 80 == 0 && i > 0)
			cout << "\n";
		cout << answer[i];
		

	}

}
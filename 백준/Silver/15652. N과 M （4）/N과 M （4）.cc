#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
//#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> arr;
void backtracking(int cnt);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	backtracking(0);

}
void backtracking(int cnt){
	if(cnt >= M){
		for(int i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for(int i = 1; i <= N; i++){
		if(arr.empty()){
			arr.push_back(i);
			cnt++;
			backtracking(cnt);
			cnt--;
			arr.pop_back();
		}else{
			if(arr.back() <= i){
				arr.push_back(i);
				cnt++;
				backtracking(cnt);
				cnt--;
				arr.pop_back();
			}
		}
	}
}







// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<sstream>
// using namespace std;
// bool print_flag = false, end_flag = false;
// string answer = "";
// bool visited[100] = {false,};
// void permutation(string input, string temp, int cnt);
// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);

// 	string input, temp;
// 	cin >> input;

// 	temp = input;
// 	sort(temp.begin(), temp.end());
// 	int cnt = 0;

// 	permutation(input, temp, cnt);

// }
// void permutation(string input, string temp, int cnt){
// 	if(end_flag) return;
// 	if(print_flag){
// 		cout << answer;
// 		end_flag = true;
// 		return;
// 	}
	
// 	if(cnt == input.length()){
// 		return;
// 	}

// 	for(int i = 0; i < input.length(); i++){
// 		if(!visited[i]){
// 			answer += temp[i];
// 			cnt++;
// 			visited[i] = true;
// 			cout << "going: " << answer << "\n";
// 			permutation(input, temp, cnt);
// 			cout << "coming: " << answer << "\n";
// 			visited[i] = false;
// 			cnt--;
// 			answer += temp[i];
// 		}
// 	}
// }
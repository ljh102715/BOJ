#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int cnt, N, M, cur;
vector<int> permutation;
void backtracking(int num);
int main(){
	cin >> N >> M;
	
	backtracking(0);

	return 0;
}
void backtracking(int num){

	if(cnt == M){
		for(int i = 0; i < M; i++)
			cout << permutation[i] << " ";
		cout <<"\n";

		return;
	}


	for(int i = 1; i <= N; i++){
		if(permutation.end() == find(permutation.begin(), permutation.end(), i) && num < i){//없으면
			permutation.push_back(i);
			cnt++;

			backtracking(i);	
			permutation.pop_back();	
			cnt--;
		}
	}

}
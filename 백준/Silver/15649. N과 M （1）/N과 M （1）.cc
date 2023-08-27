#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int cnt, N, M;
vector<int> permutation;
void backtracking();
int main(){
	cin >> N >> M;
	

	backtracking();

	return 0;
}
void backtracking(){

	if(cnt == M){
		for(int i = 0; i < M; i++)
			cout << permutation[i] << " ";
		cout <<"\n";

		return;
	}


	for(int i = 1; i <= N; i++){
		if(permutation.end() == find(permutation.begin(), permutation.end(), i)){//없으면
			permutation.push_back(i);
			cnt++;
			backtracking();	
			permutation.pop_back();	
			cnt--;
		}
	}

}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long lan[10000] = {0,};
	long answer = 0, K, N, max_lan = 0;
	cin >> K >> N;
	for(int i = 0; i < K; i++){
		cin >> lan[i];
		if(max_lan < lan[i])
			max_lan = lan[i];
	}
	long temp, low = 1, high = max_lan;//전체가 하나의 랜선일때 최대 길이
	//즉..이상적인 길이?
	while(low <= high){
		temp = 0;
		long middle = (low + high) / 2;

		for(int i = 0; i < K; i++)
			temp += lan[i] / middle;

		if(temp >= N){
			low = middle + 1;
			answer = max(answer, middle);
			
		}else{
			high = middle - 1;
		}


	}
	
	cout << answer;

}
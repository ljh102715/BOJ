#include <iostream>
using namespace std;

int main()
{
	int N, M, arr[101], best = 0, now = 0;
	cin >> N >> M;
	for(int i = 1; i<= N; i++){
		cin >> arr[i];
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j<= N; j++){
			if(i == j){continue;}
			for(int k = 1; k<= N; k++){
				if(i == k || j == k){continue;}
				now = arr[i]+arr[j]+arr[k];
				if(now >= best && now <= M){
					best = now;				
					if(best == M){break;}
				}
				now = 0;
			}
		}
	}
	
	cout << best;
}

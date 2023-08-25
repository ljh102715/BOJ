#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int one, zero, minus_one;
int arr[2187][2187];
void check(int row, int col, int size);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> arr[i][j];
	check(0, 0, N);
	cout << minus_one << "\n" << zero << "\n" << one;
}
void check(int row, int col, int size){
	int now = arr[row][col];
	bool ifSame = true;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++)
			if(now != arr[row+i][col+j]){
				ifSame = false;
				break;
			}
		if(!ifSame)
			break;
	}
	if(ifSame){
		switch(now){
			case 1:
				one++;
				break;
			case 0:
				zero++;
				break;
			case -1:
				minus_one++;
				break;
		}
	}
	else{
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				check(row + size/3 * i, col + size/3 * j, size/3);
			}
		}
	}
}
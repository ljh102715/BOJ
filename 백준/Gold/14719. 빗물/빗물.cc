#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int row, col, temp, cnt, front, back, answer = 0, map[500];
	cin >> row >> col;
	for(int i = 0; i < col; i++)
		cin >> map[i];
	
	for(int i = row; i > 0; i--){
		temp = 0, cnt = 0, front = 0, back = 0;
		for(int j = 0; j < col; j++){
			if(map[j] >= i) {
				front = j; 
				break;
				}
		}
		for(int j = col-1; j >= 0; j--){
			if(map[j] >= i) {
				back = j; 
				break;
			}
		}
		for(int j = 0; j < col; j++)
			if(map[j] >= i)
				cnt++;
		
		if(front != back && cnt >= 2)
			temp = back - front + 1 - cnt;
	
		answer += temp;
	}
	cout << answer;
}
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int board[15][15], n, col, cnt;
bool safe(int row, int col);
void recursive();
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	recursive();
	cout << cnt;
	return 0;
}
void recursive(){
	if(col >= n){
		cnt++;
		return;
	}

	for(int i = 0; i < n; i++){
		if(safe(i,col)){
			board[i][col] = 1;
			col++;
			recursive();
			col--;
			board[i][col] = 0;
		}
	}

}
bool safe(int row, int col) {
	for(int i = col; i >= 0; i--){//왼쪽 옆 검사
		if(board[row][i])
			return false;
	}
	//왼쪽 윗 대각선 검사
	for(int i = row, j = col; i >=0 && j >= 0; i--, j--)
		if(board[i][j])
			return false;
	//왼쪽 아랫 대각선 검사
	for(int i = row, j = col; i <= n && j >= 0; i++, j--)
		if(board[i][j])
			return false;
	return true;
}
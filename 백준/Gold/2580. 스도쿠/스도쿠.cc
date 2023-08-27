#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
typedef struct{
	int row;
	int col;
}blank;
blank blanks[81];
int board[10][10], cur_blank, cnt;
bool finished = false;
bool check(int row, int col, int num);
void backtracking();
int main(){
	for(int i = 1; i < 10; i++)
		for(int j = 1; j < 10; j++){
			cin >> board[i][j];	
			if(!board[i][j]){
				blanks[cnt].row = i;
				blanks[cnt].col = j;
				cnt++;
			}
		}

	backtracking();
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++)
			cout << board[i][j] << " ";
		if(i != 9)
			cout << "\n";
	}

	return 0;
}
void backtracking(){
	if(cur_blank == cnt){
		finished = true;
		return;
	}

	for(int i = 1; i < 10; i++){
			if(check(blanks[cur_blank].row, blanks[cur_blank].col, i)){
				board[blanks[cur_blank].row][blanks[cur_blank].col] = i;
				cur_blank++;
				backtracking();
				if(finished) return;				
				board[blanks[cur_blank].row][blanks[cur_blank].col] = 0;
				cur_blank--;
			}

	}
}
bool check(int row, int col, int num){
	int temp_row, temp_col;
	if(row >= 7)
		temp_row = 7;
	else if(row >= 4)
		temp_row = 4;
	else if(row >= 1)
		temp_row = 1;

	if(col >= 7)
		temp_col = 7;
	else if(col >= 4)
		temp_col = 4;
	else if(col >= 1)
		temp_col = 1;

	for(int i = temp_row; i < temp_row+3; i++)
		for(int j = temp_col; j < temp_col + 3; j++){
			if(board[i][j] == num)
				return false;
		}

	for(int i = 1; i < 10; i++){
		if(board[row][i] == num)
			return false;
	}
	for(int i = 1; i < 10; i++){
		if(board[i][col] == num)
			return false;
	}

	return true;
}
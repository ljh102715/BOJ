#include <iostream>

using namespace std;

int main() {

	int row, col, cnt = 0, best = 64, determinant,board[51][51];
	int start;
	char temp;
	cin >> row >> col;
	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= col; j++){
			cin >> temp;
			if(temp == 'W'){board[i][j] = 1;}
			else{board[i][j] = 0;}
		}
	}

	//W = 1, B = 0
	for(int i = 1; i <= row - 7; i++){
		for(int j = 1; j <= col - 7; j++){

			for(int m = 0; m<2; m++){
				start = m;
				determinant = (i + j) % 2;
				cnt = 0;
	
				for(int k = i; k <= i+7; k++){
					for(int l = j; l <= j+7; l++){
						if((k + l) % 2 == determinant){
							if(board[k][l] != start) cnt++;
						}
						else{
							if(board[k][l] == start) cnt++;
						}
					}
				}

				if(best > cnt){best = cnt;}
			}
		}
	}

	cout << best;
}
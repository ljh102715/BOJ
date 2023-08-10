#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int num;
char arr[65][65];

void compress(int row, int col, int num);

int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> num;
    for(int i = 1; i<= num; i++)
        for(int j = 1; j<=num; j++)
            cin >> arr[i][j];

    compress(1, 1, num);
    return 0;
}
void compress(int row, int col, int num){
    if(num <= 1) {cout << arr[row][col]; return;}
    bool ifSame = true;
    char start = arr[row][col];
    for(int i = row; i < row + num; i++){
        for(int j = col; j < col + num; j++){
            if(start != arr[i][j]){
                ifSame = false; break;
            }
        }
        if(!ifSame)
            break;
    }

    if(ifSame)
        cout << start;
    else{
        cout << "(";
        compress(row, col, num / 2);
        compress(row, col + num/2, num / 2);
        compress(row + num/2, col, num / 2);
        compress(row + num/2, col + num / 2, num / 2);
        cout << ")";
    }
}
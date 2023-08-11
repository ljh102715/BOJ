#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int num, back[100][100] = {0,}, row, col, cnt = 0;
    cin >> num;
    for(int i = 0; i<num;i++){
        cin >> row >> col;
        for(int j = row; j < row+10; j++){
            for(int k = col; k < col + 10; k++)
                back[j][k] = 1;
        }
    }
    for(int i = 0; i< 100; i++){
        for(int j = 0; j < 100; j++){
            if(back[i][j] == 1)
                cnt++;
        }
    }
    cout << cnt;

    return 0;
}
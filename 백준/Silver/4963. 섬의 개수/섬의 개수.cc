#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int row, col;
bool flag;
void dfs(int arr[][52], bool visited[][52], int* cnt, int cur_row, int cur_col);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1){
		cin >> col >> row;
		if(!row)
			break;
		int arr[52][52] = {0,};
		bool visited[52][52] = {false,};
		int cnt = 0;
		for(int i = 1; i <= row; i++)
			for(int j = 1; j <= col; j++)
				cin >> arr[i][j];

		for(int i = 1; i <= row; i++)
			for(int j = 1; j <= col; j++){
				flag = true;
				dfs(arr, visited, &cnt, i, j);
			}
		cout << cnt << "\n";
	}
}
void dfs(int arr[][52], bool visited[][52], int* cnt, int cur_row, int cur_col){
	if(!arr[cur_row][cur_col] || visited[cur_row][cur_col])//check if it is ocean or already visited
		return;

	if(flag){
		(*cnt)++; //one more island
	}
	flag = false;
	//check not to visit again
	visited[cur_row][cur_col] = true;

	dfs(arr, visited, cnt, cur_row+1, cur_col);
	dfs(arr, visited, cnt, cur_row, cur_col+1);
	dfs(arr, visited, cnt, cur_row-1, cur_col);
	dfs(arr, visited, cnt, cur_row, cur_col-1);
	dfs(arr, visited, cnt, cur_row+1, cur_col+1);
	dfs(arr, visited, cnt, cur_row-1, cur_col-1);
	dfs(arr, visited, cnt, cur_row-1, cur_col+1);
	dfs(arr, visited, cnt, cur_row+1, cur_col-1);
	

}
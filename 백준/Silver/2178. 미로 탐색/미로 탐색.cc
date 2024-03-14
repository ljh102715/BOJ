#include <iostream>
#include <queue>

using namespace std;

int arr[100][100] = {0,};
int visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < col; j++){
            arr[i][j] = temp[j] - '0';
        }
    }
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            visited[i][j] = -1;

    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = 1;

    while(!q.empty()){

        pair<int, int> cur = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if(x < 0 || x >= row || y < 0 || y >= col)
                continue;

            if(arr[x][y] && visited[x][y] < 0){
                q.push(make_pair(x, y));
                visited[x][y] = visited[cur.first][cur.second] + 1;
            }
        }
    }

    cout << visited[row - 1][col - 1];
    
}
#include <iostream>
#include <queue>

using namespace std;

int arr[500][500] = {0,};
int visited[500][500] = {0,};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int row, col, cnt = 0, max = 0;
    cin >> row >> col;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){

            if(arr[i][j] && !visited[i][j]){
                cnt++;
                queue<pair<int,int>> q;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                int temp_cnt = 1;

                while(!q.empty()){
                    pair<int,int> cur = q.front();  q.pop();

                    for(int k = 0; k < 4; k++){
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];
                        if(x < 0 || x >= row || y < 0 || y >= col)
                            continue;

                        if(arr[x][y] && !visited[x][y]){
                            visited[x][y] = 1;
                            q.push(make_pair(x,y));
                            temp_cnt++;
                        }
                    }

                    if(temp_cnt > max)
                        max = temp_cnt;

                }
            }
        }
    }
    cout << cnt << "\n" << max;
}
#include <vector>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int number_of_area;
int max_size_of_one_area;
int temp_cnt;
int global_m, global_n;
int copy_picture[100][100];
void bfs(int row, int col, int color);
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            copy_picture[i][j] = picture[i][j];
            
    global_m = m, global_n = n, temp_cnt = 0;
    number_of_area = 0, max_size_of_one_area = 0;
    
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(copy_picture[i][j] <= 0)
                continue;

            number_of_area++;
            bfs(i, j, copy_picture[i][j]);
            printf("%d %d %d\n", i, j, copy_picture[i][j]);
            if(temp_cnt > max_size_of_one_area)
                max_size_of_one_area = temp_cnt;
    
            temp_cnt = 0;
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
void bfs(int row, int col, int color){
    //printf("%d %d %d\n", row, col, color);
    if(row < 0 || col < 0 || row >= global_m || col >= global_n || copy_picture[row][col] != color)
        return;
    
    temp_cnt++;
    copy_picture[row][col] = -1;//check visited
    bfs(row - 1, col, color);
    bfs(row, col + 1, color);
    bfs(row + 1, col, color);
    bfs(row, col - 1, color);

}


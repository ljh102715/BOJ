#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef struct{
    int row;
    int col;
    int cnt;
    int from_dir;
}pos;
int solution(vector<string> board) {
    pos start, dest, answer;
    bool visited[100][100] = {false,};
    queue<pos> q;
    for(int i = 0; i < board.size(); i++){
        bool flag = false;
        for(int j = 0; j < board.at(i).length(); j++){
            if(board.at(i).at(j) == 'R'){
                start.row = i;
                start.col = j;
                start.cnt = 0;
                start.from_dir = -1;
                q.push(start);
            }else if(board.at(i).at(j) == 'G'){
                dest.row = i;
                dest.col = j;
                dest.cnt = -1;
                dest.from_dir = -1;
            }
        }
    }
    
    while(!q.empty()){
        pos cur = q.front();
        q.pop();
        visited[cur.row][cur.col] = true;
        if(cur.row == dest.row && cur.col == dest.col){
            return cur.cnt;
        }
        //cout << cur.row << " " << cur.col << " " << cur.cnt << "\n";
        //1상 2하 3좌 4우 에서 옴
        if(cur.row < board.size() - 1 && board[cur.row + 1][cur.col] != 'D'){//하
            pos next = cur;
            while(board[next.row + 1][next.col] != 'D' && next.row < board.size() - 1){
                next.row++;
            }
            next.cnt++;
            if(!visited[next.row][next.col])
                q.push(next);
        }
        if(cur.row > 0 && board[cur.row - 1][cur.col] != 'D'){//상
            pos next = cur;
            while(board[next.row - 1][next.col] != 'D' && next.row > 0){
                next.row--;
            }
            next.cnt++;
            if(!visited[next.row][next.col])
                q.push(next);
        }
        if(cur.col > 0 && board[cur.row][cur.col - 1] != 'D'){//좌
            pos next = cur;
            while(board[next.row][next.col - 1] != 'D' && next.col > 0){
                next.col--;
            }
            next.cnt++;
            if(!visited[next.row][next.col])
                q.push(next);
        }
        if(cur.col < board.at(0).length() - 1 && board[cur.row][cur.col + 1] != 'D'){//우
            pos next = cur;
            while(board[next.row][next.col + 1] != 'D' && next.col < board.at(0).length() - 1){
                next.col++;
            }
            next.cnt++;
            if(!visited[next.row][next.col])
                q.push(next);
        }
    }
    
    
    return -1;
}
#include <bits/stdc++.h>
using namespace std;
int row_len, col_len;
typedef struct{
    int row;
    int col;
    int cost;
}position;
int bfs(position start, position dest, const vector<string>& maps){
    int arr[100][100] = {0,};
    queue<position> q;
    q.push(start);
    while(!q.empty()){
        position here = q.front();
        q.pop();
        if(here.row == dest.row && here.col == dest.col){//arrived
            return here.cost;
        }
        //not arrived yet
        if(here.row > 0){//위
            position temp;
            temp.row = here.row - 1;
            temp.col = here.col;
            temp.cost = here.cost + 1;
            if(maps[temp.row].at(temp.col) != 'X' && !arr[temp.row][temp.col]){
                
                q.push(temp);
            }
            
            arr[temp.row][temp.col] = 1;
        }if(here.col > 0){//왼쪽
            position temp;
            temp.row = here.row;
            temp.col = here.col - 1;
            temp.cost = here.cost + 1;
            if(maps[temp.row].at(temp.col) != 'X'&& !arr[temp.row][temp.col]){
                q.push(temp);
            }
            arr[temp.row][temp.col] = 1;
        }if(here.row < row_len - 1){//아래
            position temp;
            temp.row = here.row + 1;
            temp.col = here.col;
            temp.cost = here.cost + 1;
            if(maps[temp.row].at(temp.col) != 'X'&& !arr[temp.row][temp.col]){
                q.push(temp);
            }
            arr[temp.row][temp.col] = 1;
        }if(here.col < col_len - 1){//위
            position temp;
            temp.row = here.row;
            temp.col = here.col + 1;
            temp.cost = here.cost + 1;
            if(maps[temp.row].at(temp.col) != 'X'&& !arr[temp.row][temp.col]){
                q.push(temp);
            }
            
            arr[temp.row][temp.col] = 1;
        }
        

        
    }
    return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    row_len = maps.size(), col_len = maps[0].length();
    position start, lever, exit;
    for(int i = 0; i < row_len; i++)
        for(int j = 0; j < col_len; j++){
            char type = maps[i].at(j);
            switch(type){
                case 'S':
                    start.row = i;
                    start.col = j;
                    start.cost = 0;
                    break;
                case 'L':
                    lever.row = i;
                    lever.col = j;
                    lever.cost = 0;
                    break;
                case 'E':
                    exit.row = i;
                    exit.col = j;
                    exit.cost = 0;
                    break;
            }
            
        }
    //star to lever
    int first = bfs(start, lever, maps);
    cout << "first : " << first <<endl;
    //lever to exit
    int second = bfs(lever, exit, maps);
    cout << "second : " << second <<endl;
    if(first >= 0 && second >= 0){
        answer = first + second;
        return answer;
    }
    return -1;
}
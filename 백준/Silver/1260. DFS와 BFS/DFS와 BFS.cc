#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<queue>
using namespace std;
void dfs(int pos);
void bfs();
int vertex_num, edge_num, start;
bool visited_dfs[1001] = {false,};
bool visited_bfs[1001] = {false,};
int graph[1001][1001] = {0,};
queue<int> bfs_queue;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> vertex_num >> edge_num >> start;

	for(int i = 0; i < edge_num; i++){
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;

		graph[vertex1][vertex2] = 1;
		graph[vertex2][vertex1] = 1;
	}
	visited_dfs[start] = true;
	dfs(start);
	cout << "\n";
	visited_bfs[start] = true;
	bfs_queue.push(start);
	bfs();
}
void dfs(int pos){
	cout << pos << " ";
	for(int i = 1; i <= vertex_num; i++){
		if(!visited_dfs[i] && graph[pos][i]){
			visited_dfs[i] = 1;
			dfs(i);
		}
	}

}
void bfs(){
	while(!bfs_queue.empty()){
		for(int i = 1; i <= vertex_num; i++){
			if(!visited_bfs[i] && graph[bfs_queue.front()][i]){
				visited_bfs[i] = 1;
				bfs_queue.push(i);
			}
		}
		cout << bfs_queue.front() << " ";
		bfs_queue.pop();

	}
}
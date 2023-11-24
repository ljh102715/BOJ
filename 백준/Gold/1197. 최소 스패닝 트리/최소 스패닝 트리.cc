#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> parent(10001);
bool comp(vector<int>& a, vector<int>& b){
	return a[2] < b[2];
}
int findParent(int x){
	return (parent[x] == x)? x : parent[x] = findParent(parent[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> graph;
	int answer = 0, node_cnt, edge_cnt, node1, node2, weight;
	cin >> node_cnt >> edge_cnt;

	for(int i = 0; i < edge_cnt; i++){
		cin >> node1 >> node2 >> weight;
		graph.push_back(vector<int>{node1, node2, weight});
	}
	for(int i = 1; i <= node_cnt; i++)
		parent[i] = i;
	
	sort(graph.begin(), graph.end(), comp);
	for(int i = 0; i < edge_cnt; i++){
		if(findParent(graph[i][0]) != findParent(graph[i][1])){
			parent[findParent(graph[i][1])] = findParent(graph[i][0]);
			answer += graph[i][2];
		}
	}
	cout << answer;
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, start = 0;
	vector<int> circle;
	cin >> N >> K;

	for(int i = 1; i <= N; i++)
		circle.push_back(i);
	
	cout << "<";
	while(!circle.empty()){
		start += K - 1;
		if(start >= circle.size()){
			start %= circle.size();
		}
		cout << circle.at(start);
		circle.erase(circle.begin() + start);
		if(circle.empty())
			break;
		cout << ", ";
	}
	cout << ">";

}
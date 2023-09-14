#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int arr[100000] = {0,};
int visited[100000] = {0,};
int binary_search(int left, int right, int find);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, x, cnt = 0;
	cin >> num;
	for(int i = 0; i < num; i++)
		cin >> arr[i];
	
	cin >> x;

	std::sort(arr, arr+num, less<int>());
	for(int i = 0; i < num; i++){
		if(visited[i])
			continue;

		visited[i] = 1;
		int opposite = binary_search(0, num-1, x - arr[i]);
		if(opposite < 0 || visited[opposite])
			continue;
		//cout << "arr[i] " <<  arr[i] << " " ;
		visited[opposite] = 1;
		cnt++;
	}
	cout << cnt;
}
int binary_search(int left, int right, int find){
	while(left <= right){

		int mid = (left + right) / 2;
		if(arr[mid] == find){
			return mid;
		}
		else if(arr[mid] > find){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return -1;
}
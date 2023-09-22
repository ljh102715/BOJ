#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int arr[500000] = {0,};
int arr2[500000] = {0,};
int binarySearch(int low, int high, int target);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;
	for(int i = 0; i < M; i++)
		cin >> arr2[i];

	sort(arr, arr+N);
	for(int i = 0; i < M; i++){
		cout << binarySearch(0, N-1, arr2[i]) << " ";
	}

}
int binarySearch(int low, int high, int target){

	while(low <= high){
		int middle = (low + high) / 2;
		if(target == arr[middle])
			return 1;

		if(target > arr[middle]){
			low = middle + 1;
		}else{
			high = middle - 1;
		}
	}
	return 0;
}
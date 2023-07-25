#include <iostream>

using namespace std;

int main() {

	int arr[1000];
	int num;
	cin >> num;

	for(int i = 0; i< num; i++){
		cin >> arr[i];
	}

	for(int i = 0; i< num; i++){
		for(int j = i; j < num; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for(int i = 0; i< num; i++){
		cout << arr[i] << endl;
	}
	return 0;
}
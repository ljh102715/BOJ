#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

	vector<int> arr;
	int arr2[8001] = {0,};
int main(void) {
	int num, temp, middle, second, ifFirst = 1, total = 0;
	cin >> num;

	for(int i = 0; i < num; i++){
		cin >> temp;
		arr.push_back(temp);
		arr2[temp+4000]++;
		total += temp;
	}
	sort(arr.begin(), arr.end());

	int max = *(max_element(arr2, arr2+8001));
	for(int i = 0; i < 8001; i++){
		if(arr2[i] == max){
			if(ifFirst){
				second = i;
				ifFirst = 0;
			}
			else{
				second = i;
				break;
			}
		}
	}
	
	cout << (int)round((double)total / num) << "\n";
	cout << arr[num/2] << "\n";
	cout << second-4000 << "\n";
	cout << arr[num-1] - arr[0];

}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, arr[1001], before[1001] = {0,}, after[1001] = {0,}, max = 0;
    cin >> num;
    for(int i = 1; i <= num; i++)
        cin >> arr[i];

    for(int i = 1; i <= num; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && before[i] <= before[j])
                before[i] = before[j] + 1;
        }
    }

    for(int i = num; i >= 1; i--){
        after[i] = 1;
        for(int j = num; j > i; j--){
            if(arr[i] > arr[j] && after[i] <= after[j])
                after[i] = after[j] + 1;
        }
    }


    // for(int i = 1; i <= num; i++){ 
    //     cout << before[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= num; i++){ 
    //     cout << after[i] << " ";
    // }
    // cout << endl;
    for(int i = 1; i <= num; i++){
        if(max < before[i] + after[i] - 1)
            max = before[i] + after[i] - 1;
    }
    cout << max;
	
}
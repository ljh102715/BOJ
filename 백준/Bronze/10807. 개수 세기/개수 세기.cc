#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int num, size, arr[100], cnt = 0;
    cin >> size;
    for(int i = 0; i< size; i++)
        cin >> arr[i];
    cin >> num;
    for(int i = 0; i<size; i++)
        if(arr[i] == num)
            cnt++;
    
    cout << cnt;
    return 0;
}
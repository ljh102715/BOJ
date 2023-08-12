#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool compare(int a, int b){
	return a > b;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cNum, cArr[50], box, temp, cnt = 0, max = 0;
	vector<int> bArr;
	cin >> cNum;
	for(int i = 0; i < cNum; i++){
		cin >> cArr[i];
		if(cArr[i] > max)
			max = cArr[i];
	}
	cin >> box;
	for(int i = 0; i < box; i++){
		cin >> temp;
		bArr.push_back(temp);
	}

	sort(bArr.begin(), bArr.end(), compare);
	if(max < bArr[0]) {cout << "-1"; return 0;}

	while(bArr.size() > 0){
		for(int i = 0; i < cNum; i++){
			for(int j = 0; j < bArr.size(); j++){
				if(cArr[i] >= bArr[j]){
					bArr.erase(bArr.begin() + j);
					break;
				}
			}
		}
		cnt++;
	}
	cout << cnt;
	
}
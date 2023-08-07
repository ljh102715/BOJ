#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
struct meeting{
	int start;
	int end;
};
int compare(const meeting& a, const meeting& b){
	if(a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
};
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num, cnt = 0, available = 0;
	meeting meetings[100000];
	cin >> num;
	for(int i = 0; i < num; i++){
		cin >> meetings[i].start >> meetings[i].end;
	}
	sort(meetings, meetings+num, compare);
	for(int i = 0; i < num; i++){
		if(meetings[i].start >= available){
			cnt++;
			available = meetings[i].end;
		}
	}
	cout << cnt;

}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	int num, cnt = 0;
	cin >> num; 
	for(int i = 1; i * i <= num; i++)
		cnt++;
	cout << cnt;
}
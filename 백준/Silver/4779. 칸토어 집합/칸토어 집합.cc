#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

void recur(string &a, int start, int length);
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	
	while(cin >> num){
		string a;
		num = pow(3, num);
		for(int i = 0; i < num; i++)
			a+="-";
		recur(a, 0, num);
		cout << a << "\n";
	}
}
void recur(string &a, int start, int length){
	if(length <= 1) return;

	for(int i = 0; i < length/3; i++)
		a[start + length/3 + i] = ' ';

	recur(a, start, length/3);
	recur(a, start + 2*(length/3), length/3);
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int isPalindrome(const string& a, int start, int end, int* cnt);
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, cnt;
	string a;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		cnt = 0;
		cin >> a;
		cout << isPalindrome(a, 0, a.length()-1, &cnt) << " ";
		cout << cnt << "\n";
	}
}
int isPalindrome(const string& a, int start, int end, int* cnt){
	(*cnt)++;
	if(start >= end) return 1;
	if(a.at(start) == a.at(end)){
		return isPalindrome(a, start+1, end-1, cnt);
	}
	else return 0;
}
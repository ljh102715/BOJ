#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int isPalindrome(string a, int* cnt);
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
		cout << isPalindrome(a, &cnt) << " ";
		cout << cnt << "\n";
	}
}
int isPalindrome(string a, int* cnt){
	(*cnt)++;
	if(a.length() <=1) return 1;
	if(a.at(0) == a.at(a.length()-1)){
		return isPalindrome(a.substr(1, a.length()-2), cnt);
	}
	else return 0;
}
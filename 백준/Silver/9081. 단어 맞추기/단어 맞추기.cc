#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<set>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;

	for(int i = 0; i < num; i++){
		string input;
		cin >> input;
		if(!next_permutation(input.begin(), input.end()))
			prev_permutation(input.begin(), input.end());
		cout << input << "\n";
	}
}
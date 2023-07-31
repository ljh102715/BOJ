#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<string> strings;
	string input;
	cin >> input;
	int cnt = 0;
	for(int i = 0; i < input.length(); i++){
		for(int j = i; j < input.length() + 1; j++){
			strings.push_back(input.substr(i, input.length()-j));
		}
	}
	sort(strings.begin(), strings.end());
	strings.erase(unique(strings.begin(), strings.end()), strings.end());
	strings.erase(find(strings.begin(), strings.end(), ""));
	
	cout << strings.size();
}
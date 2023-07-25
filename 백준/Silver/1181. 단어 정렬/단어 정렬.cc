#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const string& a, const string& b){
	if(a.length() == b.length()){
		return a < b;
	} else{
		return a.length() < b.length();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	vector<string> words;

	for(int i = 0; i< num; i++){
		string temp;
		cin >> temp;
		words.push_back(temp);
	}

	sort(words.begin(), words.end(), compare);
	words.erase(unique(words.begin(), words.end()), words.end());
	for(vector<string>::iterator iter = words.begin(); iter != words.end(); iter++){
		if(*iter == words.back())
			cout << *iter;
		else
			cout << *iter << "\n";
	}
}
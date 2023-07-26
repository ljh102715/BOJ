#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long num, temp;
	cin >> num;
	vector<long long> before, after;

	for(int i = 0; i < num; i++){
		cin >> temp; before.push_back(temp);
	}
	after = before;
	sort(before.begin(), before.end()); //정렬
	before.erase(unique(before.begin(), before.end()), before.end());

	for(int i = 0; i< after.size(); i++)
		cout << lower_bound(before.begin(), before.end(), after.at(i)) - before.begin() << " ";
}
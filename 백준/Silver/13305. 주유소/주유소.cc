#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int num, road[100000], city[100000], price, total = 0;
	cin >> num;
	for(int i = 0; i < num-1; i++)
		cin >> road[i];
	for(int i = 0; i < num; i++)
		cin >> city[i];

	price = city[0];
	for(int i = 0; i < num - 1; i++){
		if(city[i] < price)
			price = city[i];

		total += price * road[i];
	}
	cout << total;
}
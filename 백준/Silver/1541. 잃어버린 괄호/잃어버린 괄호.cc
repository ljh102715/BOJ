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
	
	int total = 0, temp, point = 0;
	bool ifMinus = false;
	string expr;
	cin >> expr;

	for(int i = 0; i <= expr.length(); i++){
		if(expr[i] == '+' || expr[i] == '-' || expr[i] == '\0'){
			temp = stoi(expr.substr(point, i - point));
			point = i + 1;

			if(ifMinus)
				total -= temp;
			else
				total += temp;
				
			if(expr[i] == '-') ifMinus = true;
		}
	}
	cout << total;
}
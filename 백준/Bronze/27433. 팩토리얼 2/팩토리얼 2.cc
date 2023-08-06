#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

long factorial(int num);
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long num;
	cin >> num;
	cout << factorial(num);
}
long factorial(int num){
	if(num <= 1) return 1;
	else 
		return num * factorial(num-1);
}
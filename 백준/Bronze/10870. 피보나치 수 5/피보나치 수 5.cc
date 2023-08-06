#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int fibonacci(int num);
int main(void) {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long num;
	cin >> num;
	cout << fibonacci(num);
}
int fibonacci(int num){
	if(num <= 1) return num;
	else 
		return fibonacci(num-1) + fibonacci(num-2);
}
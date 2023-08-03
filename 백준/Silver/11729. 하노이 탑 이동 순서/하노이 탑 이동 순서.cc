#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
int cnt = 1;
void recur(int num, int src, int mid, int dest);
int main(void) {

	int num;
	cin >> num;
	for(int i = 0; i < num; i++)
		cnt *= 2;
	cout << cnt-1 << "\n";
	recur(num, 1, 2, 3);
}
void recur(int num, int src, int mid, int dest){
	if(num == 1)
		cout << src << " " << dest << "\n";
	else{
		recur(num-1, src, dest, mid);
		cout << src << " " << dest << "\n";
		recur(num-1, mid, src, dest);
	}
}
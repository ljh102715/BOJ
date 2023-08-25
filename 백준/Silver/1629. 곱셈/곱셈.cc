#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
long long recur(long long a, long long b, long long c);
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	long long a, b, c;
	cin >> a >> b >> c;

	cout << recur(a, b, c) % c;
}
long long recur(long long a, long long b, long long c){
	if(b == 1) return a % c;
	else if(b == 0) return 1;

	long long temp = recur(a, b/2, c);
	temp = temp * temp % c;
	if(b % 2)//b 홀수
		return temp * a % c;
	else//b 짝수
		return temp;

}
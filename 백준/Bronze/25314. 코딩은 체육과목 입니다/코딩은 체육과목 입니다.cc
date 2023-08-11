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

    int num;
    cin >> num;
    for(int i = 0; i< num; i+=4)
        cout << "long ";
    cout << "int";


    return 0;
}
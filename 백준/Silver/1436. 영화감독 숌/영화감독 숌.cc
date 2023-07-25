#include <iostream>

using namespace std;

int main() {

	int num, cnt, stop = 0;
	cin >> cnt;
	
	for(int i = 0; ; i++){
		num = i;
		while(num > 0){

			if(num%10 == 6){
				num /= 10;
				if(num % 10 == 6){
					num /=10;
					if(num % 10 == 6){
						cnt--;
						if(cnt == 0) {cout << i; stop = 1;}
						break;
					}
				}
			}
			num /= 10;
		}
		if(stop) break;
	}
	return 0;
}
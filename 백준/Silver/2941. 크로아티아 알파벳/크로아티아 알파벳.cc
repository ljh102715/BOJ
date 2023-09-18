#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a;
	cin >> a;
	int cnt = 0;

	for(int i = 0; i < a.length(); i++){
		string temp, temp2;
		if(i < a.length()-1)
			temp = a.substr(i , 2);
		if(i < a.length() - 2)
			temp2 = a.substr(i, 3);

		if(temp2 == "dz="){
			cnt++;
			//cout << cnt << " ";
			i += 2;
		}
		else if(temp == "c=" || temp == "c-" || temp == "d-" || temp == "lj" || temp == "nj" || temp == "s=" || temp == "z="){
			cnt++;
			// cout << cnt << " ";
			i += 1;
		}else{
			cnt++;
			// cout << cnt << " ";
		}

	}
	cout << cnt;


}
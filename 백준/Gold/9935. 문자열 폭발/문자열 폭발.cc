#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	string str, str_explosion;
	vector<char> relaxed;
	bool flag = false;

	cin >> str >> str_explosion;
	
	for(int i = 0; i < str.length(); i++){
		relaxed.push_back(str[i]);
		flag = false;
		if(relaxed.size() >= str_explosion.length()){
			if(relaxed.back() == str_explosion.back()){
				for(int j = 0; j < str_explosion.length(); j++){
					
					if(relaxed.at(relaxed.size() - j - 1) == str_explosion.at(str_explosion.length()-j - 1))
						flag = true;
					else{flag = false; break;}
				} 
			}
		}
		else{continue;}

		if(flag){
			for(int j = 0; j < str_explosion.length(); j++)
				relaxed.pop_back();
		}

	}
	
	
	if(relaxed.size() <= 0)
		cout << "FRULA";//없는 경우
	else
		for(int i = 0; i < relaxed.size(); i++)
			cout << relaxed.at(i);
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<string>> strings;
	vector<int> word_lengths;
	while(!cin.eof()){	//split 
		string temp;
		vector<string> words;
		getline(cin, temp);
		if(cin.eof())
			break;
		int end;
		for(int i = temp.length(); i>=0; i--){
			if(temp[i] != ' '){
				end = i; break;
			}
		}
		while(temp[end] ==' ')
			temp.erase(end);
		temp = temp.substr(0, end);
			
		for(int i = 0; i < temp.length(); i++){
			if(temp[i] != ' '){
				string a = "";
				for(; i < temp.length(); i++){
					if(i == temp.length()-1){
						a+=temp[i];
						words.push_back(a);
						break;
					}
					else if(temp[i] == ' '){
						words.push_back(a);
						break;
					}
					a += temp[i];
				}
			}
			else{
				continue;
			}
		}
		strings.push_back(words);
	}
	for(int i = 0; i < strings.size(); i++)
		for(int j = 0; j < strings.at(i).size(); j++){
			string k = strings.at(i).at(j);
			k.erase(remove(k.begin(), k.end(), ' '), k.end());
			strings.at(i).at(j) = k;
		}

	int max_length_sentence = 0;
	for(int i = 0; i < strings.size(); i++){
		if(max_length_sentence < strings.at(i).size())
			max_length_sentence = strings.at(i).size();
	}
	for(int i = 0; i < max_length_sentence; i++){
		int max_length_word = 0;
		for(int j = 0; j < strings.size(); j++){
			if(strings.at(j).size() > i && max_length_word < strings.at(j).at(i).length())
				max_length_word = strings.at(j).at(i).length();
		}
		word_lengths.push_back(max_length_word);
	}

	for(int i = 0; i < strings.size(); i++){
		for(int j = 0; j < strings.at(i).size(); j++){
			
			cout << strings.at(i).at(j);
			if(j == strings.at(i).size()-1){
				cout << "\n";
				break;
			}
			for(int k = strings.at(i).at(j).length(); k < word_lengths.at(j); k++)
				cout << " ";
			cout << " ";
			
		}
	}

}
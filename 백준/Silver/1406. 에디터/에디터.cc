#include <iostream>
#include <list>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    list<char> l;
    list<char>::iterator it = l.begin();
    for(int i = 0; i < s.length(); i++){
        l.push_back(s[i]);
    }
    it = l.end();

    int cnt;
    cin >> cnt;

    while(cnt--){
        char opt;
        cin >> opt;
        
        if(opt == 'L'){
            if(it != l.begin())
                it--;
        }
        else if(opt == 'D'){
            if(it != l.end())
                it++; 
        }
        else if(opt == 'B'){
            if(it != l.begin()){
                it--;
                it = l.erase(it);
            }
        }
        else{
            char temp;
            cin >> temp;
            l.insert(it, temp);
        }
    }

    for(auto c : l)
        cout << c;

}
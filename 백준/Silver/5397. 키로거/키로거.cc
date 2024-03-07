#include <iostream>
#include <list>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    while(num--){
        string s;
        cin >> s;
        list<char> l;
        list<char>::iterator it = l.begin();

        for(auto c : s){
            if(c == '-'){
                if(it != l.begin()){
                    it--;
                    it = l.erase(it);
                }
            }else if(c == '<'){
                if(it != l.begin())
                    it--;
            }else if(c == '>'){
                if(it != l.end())
                    it++;
            }else{
                l.insert(it, c);
            }
        }

        for(auto c : l)
            cout << c;
        cout << "\n";
    }

}
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<string> words[1000];
    vector<int> len;
    int N = 0;

    string str;

    while (true) {
        getline(cin, str, '\n');

        if (str.empty()) {
            break;
        }

        stringstream ss(str);
        string temp;

        int idx = 0;
        while (ss >> temp) {
            words[N].push_back(temp);

            if ((int)len.size() - 1 < idx) {
                len.push_back(temp.length());
            } else if (len[idx] < temp.length()) {
                len[idx] = temp.length();
            }

            idx++;
        }

        N++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < words[i].size(); j++) {
            cout << words[i][j];

            if (j != (int)words[i].size() - 1) {
                for (int k = words[i][j].length(); k <= len[j]; k++) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
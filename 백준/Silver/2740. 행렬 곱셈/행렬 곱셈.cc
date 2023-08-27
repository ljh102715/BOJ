#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int main(){

	int a[100][100], b[100][100];

	int n, m, k, result, col = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	cin >> m >> k;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < k; j++)
			cin >> b[i][j];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			result = 0;
			for(int l = 0; l < m; l++){
				result += a[i][l] * b[l][j];
			}
			cout << result << " ";
		}
		cout << "\n";

	}
	return 0;
}
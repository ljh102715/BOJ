#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    unsigned long long arr[100000];
    unsigned long long N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr+N);
    unsigned long long second_high = M * arr[0], second_low = 1, second_mid, ans = second_high, sum;

    while(second_high >= second_low){
        sum = 0;
        second_mid = (second_high + second_low) / 2;

        for(int i = 0; i < N; i++)
            sum += second_mid / arr[i];

        if(sum >= M){
            ans = min(ans, second_mid);
            second_high = second_mid - 1;
        }
        else
            second_low = second_mid + 1;

    }

    cout << ans;
}
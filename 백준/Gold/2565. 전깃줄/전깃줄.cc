#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
struct line{
    int left;
    int right;
};
bool compare(line &a, line &b){
    return a.left < b.left;
}
bool ifCrossed(line &a, line &b){
    if((a.left > b.left && a.right < b.right)||(a.left < b.left && a.right > b.right))
        return true;
    return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int num, temp;
    int dp[101] = {0,};
    line lines[101];
    cin >> num;
    for(int i = 1; i <= num; i++)
        cin >> lines[i].left >> lines[i].right;
    
    sort(lines, lines + num + 1, compare);
    for(int i = 1; i <= num; i++){
        temp = 0;
        for(int j = 1; j < i; j++){
            if(!ifCrossed(lines[i], lines[j])){
                if(temp < dp[j])
                    temp = dp[j];
            }
        }
        dp[i] = temp + 1;
    }
    cout << num - *max_element(dp, dp + num + 1);
}
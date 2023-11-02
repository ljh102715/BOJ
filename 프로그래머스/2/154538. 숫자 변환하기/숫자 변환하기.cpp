#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int solution(int x, int y, int n) {
    int answer = 0, dp[1000001];
    
    for(int i = 0; i < 1000001; i++) 
        dp[i] = 1000000;
    
    dp[x] = 0;
    
    if(x == y) 
        return 0;
    
    for(int i = x + 1; i <= y; i++){
            
            int min_temp = 1000000;
            if(i - n >= 0)
                min_temp = dp[i - n] + 1;

            if(i % 2 == 0)
                min_temp = min(min_temp, dp[i / 2] + 1);

            if(i % 3 == 0)
                min_temp = min(min_temp, dp[i / 3] + 1);

            dp[i] = min_temp;
    }
    
    if(dp[y] >= 1000000) 
        answer = -1;
    else 
        answer = dp[y];
    
    return answer;
}
/*

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int a=dungeon.size(), b=dungeon[0].size();
        vector<vector<int>> dp(a, vector<int>(b, 11111111));
        for(int i=a-1; i>=0; i--) {
            for(int j=b-1; j>=0; j--) {
                if(i==a-1 && j==b-1)
                    dp[i][j] = max(1, 1 - dungeon[i][j]);
                else if(i==a-1)
                    dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
                else if(j==b-1)
                    dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
                else
                    dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};
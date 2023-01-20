/*
You wrote down many positive integers in a string called num. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was non-decreasing and that no integer had leading zeros.

Return the number of possible lists of integers that you could have written down to get the string num. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: num = "327"
Output: 2
Explanation: You could have written down the numbers:
3, 27
327
Example 2:

Input: num = "094"
Output: 0
Explanation: No numbers can have leading zeros and all numbers must be positive.
Example 3:

Input: num = "0"
Output: 0
Explanation: No numbers can have leading zeros and all numbers must be positive.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 1000000007;
    vector<int> nne;
    
    bool ge(const string& s, const vector<vector<int>>& p, 
            int l1, int r1, int l2, int r2) {
        int l = p[l2][l1];
        if (l >= r1-l1+1) return true;
        return s[l1+l] >= s[l2+l];
    }
    
    int numberOfCombinations(string s) {
        int n = s.size();
        vector<vector<int>> f(n+1, vector<int>(n+1));
        vector<vector<int>> p(n+1, vector<int>(n+1)); 
        p[n-1][n] = 0;
        for (int i=n-2; i>=0; --i)
            for (int j=n-1; j>i; --j) {
                p[i][j] = s[i]==s[j] ? (p[i+1][j+1]+1) : 0;
            }
        for (int i=1; i<=s.size(); ++i) {
            for (int j=1; j<i; ++j) {
                if (f[i-j][j] && i>=2*j && 
                    s[i-j]!='0' &&
                    ge(s, p, i-j, i-1, i-j-j, i-j-1)) {
                    f[i][j] = f[i-j][j];                
                } else if (s[i-j]!='0') {
                    f[i][j] = f[i-j][min(j-1, i-j)];
                }
                f[i][j] = (f[i][j-1] + f[i][j]) % M;
            }
            f[i][i] = s[0]=='0' ? f[i][i-1] : f[i][i-1]+1;
        }
        return f[n][n];
    }
};
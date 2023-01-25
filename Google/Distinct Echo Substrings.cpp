/*
Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).

 

Example 1:

Input: text = "abcabcabc"
Output: 3
Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
Example 2:

Input: text = "leetcodeleetcode"
Output: 2
Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
 
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int distinctEchoSubstrings(string s) {
        int mod = INT_MAX, base = 28, n = s.size();
        unordered_map<long long, int> m;
        vector<long long> ChkVal(n+1);
        long long rmv = 1;
        for(int i = 1; i <= n/2; i++)
        {
            long long hash = 0;
            int l = 0, appear = 0;
            for(int j = 0; j < n; j++)
            {
                 hash = (( hash * base ) % mod  + (s[j] - 'a' + 1))%mod;
                 if(j-l == i-1) 
                 {
                     ChkVal[j]=hash;
                     if(appear > 0) 
                     {
                         if(ChkVal[j-i]==hash)
                            m[hash]++;
                     }
                     appear++;
                     hash = (hash - ((s[l] - 'a' + 1)*rmv)%mod)%mod;
                     if(hash<0) hash+=mod;
                     l++;
                }
            }
             
            rmv = (rmv * base)%mod;
        }
        return m.size();
    }
};
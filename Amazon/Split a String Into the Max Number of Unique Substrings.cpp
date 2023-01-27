/*
Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
Example 2:

Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
Example 3:

Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   void solve(string s,int& ans,set<string>st,int ind,int n)
   {
     if (ind>=n)
     {
         int curr=st.size();
         if (curr>ans)
         {
         ans=max(ans,curr);
         for (auto it:st)
         {
             cout<<it<<" ";
         }
         }
     }
     for (int i=ind;i<n;i++)
     {
         if (st.find(s.substr(ind,ind-i+1))==st.end())
         {
             string temp=s.substr(ind,i-ind+1);
             st.insert(temp);
           
             solve(s,ans,st,i+1,n);

            st.erase(temp);
         }
     }
   }
    int maxUniqueSplit(string s) {
        set<string>st;
        int ans=INT_MIN;
        int n=s.size();
        solve(s,ans,st,0,n);
        return ans;
    }
};
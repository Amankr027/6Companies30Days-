/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
Example 2:

Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bs(vector<int> &arr, int x){
        int start = 0;
        int end = arr.size()-1;
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (arr[mid] <= x)
                start = mid + 1;
            else
            {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans==-1 ? ans : arr[ans];
    }
    

    int numMatchingSubseq(string s, vector<string>& words) {
	
		
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
          
        int count = words.size();
		
        for(auto w : words){
            int prev = -1;
            for(int j=0;j<w.size();j++){
				
                int x = bs(mp[w[j]],prev);
				
                if(x == -1){
                    count--;
                    break;
                }
				
                else{
                    prev = x;
                }
            }
        }
        return count;
    }
};
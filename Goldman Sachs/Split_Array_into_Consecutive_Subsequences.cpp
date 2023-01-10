/*
You are given an integer array nums that is sorted in non-decreasing order.

Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).

 

Example 1:

Input: nums = [1,2,3,3,4,5]
Output: true
Explanation: nums can be split into the following subsequences:
[1,2,3,3,4,5] --> 1, 2, 3
[1,2,3,3,4,5] --> 3, 4, 5
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int> frq;
        for(int x: nums) frq[x]++;
        
        
        unordered_map<int,int> need;
        
        for(int n: nums){
            
            if(frq[n] == 0) continue;
            
            if(need[n] > 0){
                need[n]--;
                frq[n]--;
                
                need[n+1]++; 
            }
            
          
            else if(frq[n]>0 && frq[n+1]>0 && frq[n+2]>0){
                frq[n]--;
                frq[n+1]--;
                frq[n+2]--;
                
                
                need[n+3]++;
            }
            
            
            else{
                return false;
            }
        }
        
        return true;
    }
};
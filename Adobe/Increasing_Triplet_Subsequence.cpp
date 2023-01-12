/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.
Example 2:

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int s =nums.size();       // size 0f the integer array
        if(s<3)return false ;    // if size is less than 3 then it is not possible to have any triplet 

        int l = INT_MAX , m = INT_MAX ; // intializing left and mid to max 

        for(int i =0 ;i<s;i++){
            // iterate in the whole array 
            
            if(nums[i]>m){
                return true; 
                // if nums[i] is greater than mid then it is also greater than left and it can be the third element in the     triplet that is greatrer than both | so return true 
            }

            else if(nums[i]>l && nums[i] < m){
                m = nums[i];  // this condition satisfies such that left < nums[i] < mid but it can be possible m is INT_MAX
            }

            
            else if(nums[i] < l){
                l = nums[i];
                 //if nums[i] less than left then the  nums[i] = left because we find a smaller value than previous value of left 
                }
        }

        return false ; // no Increasing Triplet Subsequence found .  

        
    }
};
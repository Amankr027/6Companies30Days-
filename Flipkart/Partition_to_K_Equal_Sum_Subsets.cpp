/*
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    private:

    bool solve(vector<int> nums,vector<bool>& visited,int currsum,int idx,int subsetsum,int k){
        if(k==0){
            return true;}

        if(currsum>subsetsum){
            return false;
}
        if(currsum==subsetsum){
            return solve(nums,visited,0,0,subsetsum,k-1);
        }

        for(int i=idx;i<nums.size();i++){
            if(visited[i]) {
                continue;}
            visited[i] = true;
            if(solve(nums,visited,currsum+nums[i],i+1,subsetsum,k)){
              return true;}

            visited[i] = false;
		
            if(currsum==0){
            break;}
        }
        return false;
    }

public:

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n){
           return false;
}
        int sum=0;
        for(auto n : nums)
            sum += n;
       if (nums.size() < k || sum % k){
        return false;
        }
        int subsetsum = sum/k;
        vector<bool> v(n,false);

        sort(nums.begin(), nums.end(), greater<int>());
        return solve(nums,v,0,0,subsetsum,k);
    }
    
};
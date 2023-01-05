/*
You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. Find the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.

 

Example 1:

Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
Output: 3
Explanation:
There are 3 pairs that satisfy the conditions:
1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
Therefore, we return 3.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    long long int count; 
    void checkCount(vector<int>& nums, int s, int mid, int e,int d)
    {

        
        int l = s, r = mid + 1;
        while(l <= mid && r <= e)
        {
            if(nums[l]<=(nums[r]+d)) 
            {
                count += (e - r+1);
                l++;
            }
            else      
            {
                r++;
            }
        }
        
        sort(nums.begin() + s, nums.begin() + e + 1);  
        return;
         
    }
    void mergeSort(vector<int>& nums, int s, int e,int d)
    {
        if(s == e) 
            return;
        
        int mid = (s + e)/2;
        mergeSort(nums,s, mid,d);
        mergeSort(nums,mid+1,e,d);
        
        checkCount(nums,s,mid,e,d);
        return;
        
    }
    long long numberOfPairs(vector<int>& a, vector<int>& b, int d) 
    {
        count = 0;
        int n = a.size();
        vector<int>c(n);  
        
        for(int i=0;i<n;i++)
        c[i]=a[i]-b[i];               
			
        mergeSort(c,0,n-1,d);
		
        return count;
    }
};
/*
The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,3,2]
Output: 14
Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
2 * (2+3+2) = 2 * 7 = 14.
Example 2:

Input: nums = [2,3,3,1,2]
Output: 18
Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
3 * (3+3) = 3 * 6 = 18.
Example 3:

Input: nums = [3,1,5,6,4,2]
Output: 60
Explanation: The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
4 * (5+6+4) = 4 * 15 = 60.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumMinProduct(vector<int>& arr) {
        long long mod = 1e9 + 7;
        int n = arr.size();
        
        
        vector<long long> prefix(n, 0); 
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
  
        stack<int> st;
         vector<int> left(n, -1);
         vector<int> right(n, n);
        
        for(int i = 0; i < n; i++)
        {
            while(st.empty() == false && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = st.top();
            }
            
            st.push(i);
        }
        
        
        
        while(st.empty() == false)
        {
            st.pop();
        }
        
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(st.empty() == false && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                right[i] = n;
            }
            else
            {
                right[i] = st.top();
            }
            
            st.push(i);
        }
         
       
        long long max_sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            long long sum = 0;
            
            sum += prefix[right[i] - 1];
            
            if(left[i] >= 0)
            {
                sum -= prefix[left[i]];
            }
            
            sum *= arr[i];
            
            max_sum = max(max_sum, sum);
        }
        
        return max_sum % mod;
    }
};


/*
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    

    int countPref(int n, long long prefix)
    {
        long long offset = 10;
        long long target = n;
        int total = 0;
        for(int i=1;i<=9;i++)
        {
            long long minv = prefix * offset;
            long long maxv = minv + offset-1;
            
            
            if(target < minv)break;
            
            total+= min(target,maxv) - minv + 1;
            
            offset = offset * 10;
        }
        
        return total+1;
    }
    
    int findKthNumber(int n, int k, int prefix =0) {

 
        if(k>0)
        {
           
            for(int i= (prefix==0)?1:0;i<=9;i++)
            {
                int prefixCount = countPref(n,10*prefix+i);
                if(k<=prefixCount) return findKthNumber(n,k-1,10*prefix+i);
                k-=prefixCount;
            }            
        }
        
        return prefix;
    }
};
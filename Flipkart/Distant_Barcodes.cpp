/*
In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

Example 1:

Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        vector<int>ans;
        while(!pq.empty())
        {
            int a=pq.top().first;
            int n=pq.top().second;
            ans.push_back(n);
            a--;
            pq.pop();
            if(pq.size()>0)
            {
                int b=pq.top().first;
                int m=pq.top().second;
                ans.push_back(m);
                b--;
                pq.pop();
                if(b>0)
                {
                    pq.push({b,m});
                }
                if(a>0)
                {
                pq.push({a,n});
                }
            }
            
        }
        return ans;
    }
};
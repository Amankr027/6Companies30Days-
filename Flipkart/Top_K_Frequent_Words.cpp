/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
       static bool comp(pair<int,string> &a,pair<int,string> &b)
    {
        if(a.first!=b.first) return a.first>b.first;
        else return a.second<b.second;
    }
public:

    vector<string> topKFrequent(vector<string>& w, int k) {

        unordered_map<string,int> m;
        for(int i = 0; i < w.size(); i++)
        {
            m[w[i]]++;
        }

        vector<pair<int,string>> v;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            v.push_back({it->second,it->first});
        }
        sort(v.begin(),v.end(),comp);

        auto it = v.begin();
        vector<string> ans;
        while(k--)
        {
            ans.push_back(it->second);
            it++;
        }

        return ans;
    }
};
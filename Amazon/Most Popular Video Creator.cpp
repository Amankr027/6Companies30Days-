/*
You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.

The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.

If multiple creators have the highest popularity, find all of them.
If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.

 

Example 1:

Input: creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
Output: [["alice","one"],["bob","two"]]
Explanation:
The popularity of alice is 5 + 5 = 10.
The popularity of bob is 10.
The popularity of chris is 4.
alice and bob are the most popular creators.
For bob, the video with the highest view count is "two".
For alice, the videos with the highest view count are "one" and "three". Since "one" is lexicographically smaller than "three", it is included in the answer.
Example 2:

Input: creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
Output: [["alice","b"]]
Explanation:
The videos with id "b" and "c" have the highest view count.
Since "b" is lexicographically smaller than "c", it is included in the answer.

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& i, vector<int>& v) {
        map<string,long> mp;
        int j=0;
        for(auto it : c){
            mp[it] += v[j++];
        }
        map<long,vector<string>> mpp;
        for(auto it : mp){
            mpp[it.second].push_back(it.first);
        }
        vector<string> popular = mpp.rbegin()->second;
        map<string,map<int,set<string>>> m;
        for(int j=0;j<c.size();j++){
            m[c[j]][v[j]].insert(i[j]);
        }
        vector<vector<string>> ans;
        for(int j=0;j<popular.size();j++){
            auto it = m[popular[j]].rbegin()->second;
          
            ans.push_back({popular[j],*it.begin()});
        }
        return ans;
    }
};
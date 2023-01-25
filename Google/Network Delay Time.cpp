/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0; i<times.size(); i++) {
            int x = times[i][0];
            int y = times[i][1];
            int z = times[i][2];
            adj[x].push_back({y,z});
        }
        
       
        priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
        
        vector<int> distance(n+1, INT_MAX);
        distance[0]=0;
        
        pq.push({0,k});
        distance[k] = 0;
        
        while(!pq.empty())  {
            
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int node = it.second;
            
            for(auto it : adj[node])    {
                int adjNode = it.first;
                int wt = it.second;
                
                int curr = wt + dist;
                
                if(curr<distance[adjNode])  {
                    distance[adjNode] = curr;
                    pq.push({curr,adjNode});
                }
            }
        }
        
        int mx = -1;
        for(int i=0; i<n+1; i++)  {
            
            if(distance[i]==INT_MAX){
                return -1;
            }
            mx = max(distance[i],mx);
        }
        
        return mx;
    }
};
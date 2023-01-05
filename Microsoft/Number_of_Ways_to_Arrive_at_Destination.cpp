/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<long long, long long>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n);
        
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        long long mod = 1e9+ 7;
        
        while(!pq.empty()){
            
            long long nodeWt = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            
            for(auto i: adj[node]){
                
                long long child = i.first;
                long long childWt = i.second;
                
                if(childWt + nodeWt < dist[child]){
                    dist[child] = childWt + nodeWt;
                    pq.push({dist[child], child});
                    ways[child] = ways[node];
                }
                else if(childWt + nodeWt == dist[child]){
                    ways[child] = (ways[child] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1]%mod;
        
    }
};
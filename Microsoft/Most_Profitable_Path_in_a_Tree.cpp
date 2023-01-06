/*
There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

the price needed to open the gate at node i, if amount[i] is negative, or,
the cash reward obtained on opening the gate at node i, otherwise.
The game goes on as follows:

Initially, Alice is at node 0 and Bob is at node bob.
At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
If the gate is already open, no price will be required, nor will there be any cash reward.
If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
Return the maximum net income Alice can have if she travels towards the optimal leaf node.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> Adj;
    vector<int> visited;
    vector<int> Vpath_B;

    int find_path_B(int n){
        if(n == 0){Vpath_B.push_back(n); return 1;}
        
        if(visited[n] == 1){return 0;}
        visited[n] = 1;
        
        for(auto &v: Adj[n]){
            int flag = find_path_B(v);
            if(flag != 1){continue;}
            
            Vpath_B.push_back(n);
            return 1;
        }
        
        return 0;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int l = amount.size();
        Adj.resize(l, vector<int>());
        for(auto &E:edges){
            int u = E[0], v = E[1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
 
        visited.resize(l, 0);
        find_path_B(bob);

        
        amount[bob] = 0;
        Vpath_B.pop_back();
        
        
        using pii = pair<int,int>;
        int val = amount[0];
        queue<pii> Q({{0,val}});
        int Max = INT_MIN;
        
        vector<int> visited2(l, 0);
        visited2[0] = 1;
        
        while(!Q.empty()){
            int lq = Q.size();
			
			
            int n_bob = -1;
            if(!Vpath_B.empty()){
                n_bob = Vpath_B.back();
                Vpath_B.pop_back();
            }

		
            while(lq--){
                int u = Q.front().first;
                int val = Q.front().second;
                Q.pop();
                
         
                if(Adj[u].size() == 1 && u != 0){ //leaf
                    Max = max(Max, val);
                    continue;
                }
                
                for(int &v: Adj[u]){
                    if(visited2[v] == 1){continue;}
                    visited2[v] = 1; 
                    
                    if(v != n_bob){
                        Q.push({v, val+ amount[v]});
                        continue;
                    }
                    
                    Q.push({v, val+amount[v]/2});
                }
            }
            
		
            if(n_bob != -1){amount[n_bob] = 0;}
        }
        
        return Max;
        
    }
};
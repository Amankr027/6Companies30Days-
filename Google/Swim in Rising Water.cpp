/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

 

Example 1:


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int n = grid.size();
       priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
       pq.push({grid[0][0], 0, 0});
       vector<vector<bool>> visited(n, vector<bool>(n, false));
       int dir[5] = {-1, 0, 1, 0, -1};
       int  time = 0;
       while(!pq.empty()){
          vector<int> t = pq.top();
          pq.pop();
          int waitTime = t[0];
          int x = t[1];
          int y = t[2];
          time = max(time, waitTime);
          if(x == n-1 && y == n-1) return time;
          if(!visited[x][y]){
              visited[x][y] = true;
              for(int k = 0; k<4; k++){
                  int i = x + dir[k];
                  int j = y + dir[k+1];
                  if(i>=0 && i<n && j>=0 && j < n && !visited[i][j]){
                      pq.push({grid[i][j], i, j});
                  }
              }
          }
       }
       return 0;
    }
};
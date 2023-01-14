/*
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

 

Example 1:

Input: n = 3, k = 2, row = 0, column = 0
Output: 0.06250
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double dp[26][26][101];
    int dirs[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    double knightProbability(int n, int k, int row, int column) {
        return dfs(n,k,row,column);
    }
    double dfs(int n,int k,int r, int c)
    {
        if(r<0||r>=n||c<0||c>=n)
            return 0.0;
        if(k==0)
            return 1.0;
        if(dp[r][c][k]>0.0)
            return dp[r][c][k];
        double probability=0.0;
        for(int i=0;i<8;i++)
        {
            probability+=dfs(n,k-1,r+dirs[i][0],c+dirs[i][1])/8.0;
        }
        return dp[r][c][k]=probability;
    }
};
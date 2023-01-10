/*
You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

 

Example 1:


Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        vector <int> top3;
        priority_queue <int> pq;
        
        int r = grid.size();
        int c = grid[0].size();
        
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                pq.push(grid[i][j]);
            }
        }
        
        
        int h = 1;
        int height = (2 * h) + 1;
        
        
        while (height <= r && height <= c) {
            
            for (int i = 0; i < r && (r - i) >= height; i++) {
                for (int j = h; j < c - h; j++) {
                    
                    int s = 0;
                    
                    int top = grid[i][j];
                    s += top;
                    
                   
                    for (int li = 1; li <= h; li++) {
                        s += grid[i + li][j - li];
                    }
                    
                    
                    for (int ri = 1; ri <= h; ri++) {
                        s += grid[i + ri][j + ri];
                    }
                    
                    int bottom = grid[i + height - 1][j];
                    
                    int bi = i + height - 1;
                    
                    
                    for (int bl = 1; bl <= (h - 1); bl++) {
                        s += grid[bi - bl][j - bl];
                    }
                    
                   
                    for (int br = 1; br <= (h - 1); br++) {
                       s += grid[bi - br][j + br]; 
                    }
                    
                    s += bottom;
                    
                    
                    pq.push(s);
                }
            }
            
            h += 1;
            height = (2 * h) + 1;
        }
        
        
        unordered_set <int> top;
        int k = 3;
        
        while (k > 0 && !pq.empty()) {
            int el = pq.top(); pq.pop();
            if (top.find(el) == top.end()) {
                top.insert(el);
                k--;
            }
        }
        
        for (auto i: top) {
            top3.push_back(i);
        }
        
       
        sort(top3.begin(), top3.end(), greater <int>());
        
        return top3;
    }
};
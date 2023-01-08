/*
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

 

Example 1:

Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int getD(vector<int> &p1, vector<int> &p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int cnt = 0, n = points.size();
        for(int i = 0; i < n; i++)
        {
            map<int, int> mp;
            for(int j = 0; j < n; j++)
            {
                if(i != j)
               {     
                
                int tmp = getD(points[i], points[j]);
                
                    
               
                mp[tmp]++;}
                
            }
             for(auto it : mp){
                    if(it.second <= 1) continue;
                    cnt += (it.second * (it.second - 1));
                }
        }
         
        return cnt;
    }
    
    
};
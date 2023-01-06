/*
Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).

 

Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int find_d(vector<int>& a, vector<int>& b) {
        return pow((b[0]-a[0]), 2) + pow((b[1]-a[1]), 2);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d12 = find_d(p1, p2),
            d13 = find_d(p1, p3),
            d14 = find_d(p1, p4),
            d24 = find_d(p2, p4),
            d23 = find_d(p2, p3),
            d34 = find_d(p3, p4);

        unordered_set <int> s;
        s.insert({d12, d13, d14, d24, d23, d34});

        return !s.count(0) && s.size() == 2;

    }
};
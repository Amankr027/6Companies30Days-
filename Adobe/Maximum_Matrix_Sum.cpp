/*
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:


Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
		
        int negs = 0;
        long long min_val = INT_MAX;
        long long sum = 0;
        for(auto i : matrix){
            for(int j : i){
                sum += abs(j);
                if(j < 0) negs++;
                if(abs(j) < min_val) min_val = abs(j);
            }
        }
        if(negs % 2 == 0) return sum;
        else return sum - min_val*2;
    }
};

/*
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int x=-k;x<=k;x++){
                    if(i+x>=0 && i+x<n){
                        int l=max(j-k,0);
                        int r=j+k+1;
                        a[i+x][l]+=mat[i][j];
                        if(r<m) a[i+x][r]-=mat[i][j];
                    }
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<m;j++){
                sum+=a[i][j];
                a[i][j]=sum;
            }
        }
        return a;
    }
};
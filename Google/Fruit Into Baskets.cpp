/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set<int> s;
        for(int it : fruits){
            s.insert(it);
        }
        if(s.size() <= 2) return fruits.size();

        fruits.push_back(100001);
        int n = fruits.size();
        int j = 0;
        int ttl = 0;
        vector<int>f(100005);
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(f[fruits[i]] == 0 && ttl == 2){
                maxi = max(maxi , i-j);
                while(j<i){
                    if(f[fruits[j]]>1){
                        f[fruits[j]]--;
                        j++;
                    }
                    else if(f[fruits[j]] == 1){
                        f[fruits[j]]--;
                        j++;
                        break;
                    }
                }
                f[fruits[i]]++;
            }
            else if(f[fruits[i]] == 0){
                ttl++;
                f[fruits[i]]++;
            }
            else{
                f[fruits[i]]++;
            }
        }
        return maxi;
        
    }
};
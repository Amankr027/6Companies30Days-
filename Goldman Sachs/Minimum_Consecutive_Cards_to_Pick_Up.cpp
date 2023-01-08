/*
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

 

Example 1:

Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
       
        int ans = INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<cards.size();i++){
            if(mp.find(cards[i])!=mp.end()){
                ans = min(ans,i-mp[cards[i]]+1);
            }
            mp[cards[i]] = i;
        }
        if(ans==INT_MAX){ 
            return -1; }
        return ans;
    }
};
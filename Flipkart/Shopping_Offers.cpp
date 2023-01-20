/*
In LeetCode Store, there are n items to sell. Each item has a price. However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given an integer array price where price[i] is the price of the ith item, and an integer array needs where needs[i] is the number of pieces of the ith item you want to buy.

You are also given an array special where special[i] is of size n + 1 where special[i][j] is the number of pieces of the jth item in the ith offer and special[i][n] (i.e., the last integer in the array) is the price of the ith offer.

Return the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers. You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special offers as many times as you want.

 

Example 1:

Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
Output: 14
Explanation: There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B. 
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
Example 2:

Input: price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
Output: 11
Explanation: The price of A is $2, and $3 for B, $4 for C. 
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
You cannot add more items, though only $9 for 2A ,2B and 1C.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool take_offer(vector<int> &off , vector<int> &need)
    {
        int n = need.size();
        for( int i = 0 ; i < n ; ++i )
        {
            if( off[i] > need[i] )
            return false;
        }
        return true;
    }
    
    int fun( int ind , vector<int> &needs , vector<vector<int>> &special ,vector<int> &price)
    {
        if( ind == -1 )  
        {
            int sum = 0 ;
            for( int i = 0 ; i  < needs.size() ; ++i )
            {
                sum += ( needs[i] * price[i]);
            }
            return sum ;

        }

        int nottake = fun(ind-1,needs,special,price);
        int take = 1e9;
        if( take_offer(special[ind] ,needs))
        {   
            for( int i  = 0 ; i < needs.size() ; ++i )
            {
                needs[i] -= (special[ind][i]);
            }
            take = special[ind][needs.size()] + fun(ind , needs,special,price);
             for( int i  = 0 ; i < needs.size() ; ++i )
            {
                needs[i] += (special[ind][i]);
            }
           
        }
        return min(take,nottake);

    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = needs.size();    
        return fun(special.size()-1 , needs,special,price);      
    }
};
/*
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: n = 6, delay = 2, forget = 4
Output: 5
Explanation:
Day 1: Suppose the first person is named A. (1 person)
Day 2: A is the only person who knows the secret. (1 person)
Day 3: A shares the secret with a new person, B. (2 people)
Day 4: A shares the secret with a new person, C. (3 people)
Day 5: A forgets the secret, and B shares the secret with a new person, D. (3 people)
Day 6: B shares the secret with E, and C shares the secret with F. (5 people)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
    #define ll long long
    
        vector<ll> v(n+1,0);
        
        
        
        v[0] = 1; 
        int mod = 1e9 + 7;
        for(int i =0 ;i < n;i ++)
        {
            if(v[i] == 0)
                continue;
            for(int j = i + delay;j < n && (j-i)  < forget;j++) 
            {
                v[j] += v[i];
                v[j] = v[j]%mod;
            }
        }
        
        ll ans = 0;
     
        for(int i = n-1;i >= n-forget;i--)
        {
            ans += v[i];
            ans = ans%mod;
        }
        
        return ans;
    }
	
	

    
};
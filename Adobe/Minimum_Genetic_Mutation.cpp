/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int s = bank.size(); 
        
        unordered_set<string> st; 
        for(int i = 0; i < s; i++) 
        {
           st.insert(bank[i]);
        }
        
       
        if(st.find(end) == st.end())
        {
            return -1;
        }
        
       
        vector<char> ch = {'A', 'C', 'G', 'T'};
        
        
        unordered_set<string> vis;
        
        int ans = 0; 
        
        queue<string> q; 
        q.push(start); 
        vis.insert(start); 
        
      
        while(!q.empty())
        {
            int n = q.size(); 
            while(n--)
            {
                string curr = q.front(); 
                q.pop(); 
                
                if(curr == end) 
                {
                    return ans;
                }
                
                
                for(int i = 0; i < 8; i++)
                {
                    char orig = curr[i]; 
                    
                   
                    for(int j = 0; j < 4; j++) 
                    {   
                        curr[i] = ch[j];
                        
                        
                        if(st.find(curr) != st.end())
                        {
                            
                            if(vis.find(curr) == vis.end())
                            {
                                q.push(curr); // then push into queue
                                vis.insert(curr); // and also put into vis
                            }
                        }
                    }
                    
                    curr[i] = orig;
                }
            }
            ans++; 
        }
        
        return -1; 
    }
};
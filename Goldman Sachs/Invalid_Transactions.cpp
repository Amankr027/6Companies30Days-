/*
A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

Return a list of transactions that are possibly invalid. You may return the answer in any order.

 

Example 1:

Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
Output: ["alice,20,800,mtv","alice,50,100,beijing"]
Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector<string> invalidTransactions(vector<string>& transactions) {
        
        vector<string>n;
        vector<int>t;
        vector<int>a;
        vector<string>c;

        vector<string>res;
        
		int key=0;
        for(auto str:transactions){
            stringstream ss(str);
            string s;
            
			
            while(getline(ss,s,',')){
                if(key==0){
                    n.emplace_back(s);
                    key=1;
                }
                else if(key==1){
                    t.emplace_back(stoi(s));
                    key=2;
                }
                else if(key==2){
                    a.emplace_back(stoi(s));
                    key=3;                    
                }
                else if(key==3){
                    c.emplace_back(s);
                    key=0;                    
                }
            }                    
        }
        
		 int j=0;
        for(auto it:a){
            if(it>1000){
                res.emplace_back(transactions[j]);                
            }
            j++;
        }
       
        
        for(int i=0;i<transactions.size();i++){
            for(int j=0;j<transactions.size();j++){
                if(n[i]==n[j] && c[i]!=c[j]){
                    if(abs(t[i]-t[j])<=60){
                        if(a[i]<=1000){
                            res.emplace_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
		
        return res;
    }
};
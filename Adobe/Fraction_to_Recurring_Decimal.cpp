/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
       string ans = "";

if (!numerator) {
            return "0";
        }
        
        if (numerator > 0 ^ denominator > 0) {
            ans += '-';
        }
        long num = labs(numerator),  den = labs(denominator);
   

       long q = num/den;
       long r = num%den;
       ans += to_string(q);

       if(r==0){
           return ans;

       }
       else{
           ans +=".";
       }
       unordered_map<int , int> map;
       while(r != 0){
           if(map.find(r) != map.end()){
               int len = map[r];
               ans.insert(len,"(");
               ans += ")";
               break;
           }
           else{
               map[r] = ans.size();
               r*=10;
               q = r/den;
               r = r%den;
               ans += to_string(q);
           }
       }
       return ans;
    }
};
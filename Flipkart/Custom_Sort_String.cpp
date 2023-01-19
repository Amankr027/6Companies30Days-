/*
You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.

 

Example 1:

Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
Example 2:

Input: order = "cbafg", s = "abcd"
Output: "cbad"
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        string s1,s2;
        int a[26]={0};
        for(char c: order){
            a[c - 'a']++;
        }
        for(char c: s){
            if(a[c - 'a'] == 0 ){
                s2 +=c;
            }
            else{
                a[c - 'a']++;
            }
        }
        for(char c: order){
            while(a[c-'a']>1){
                s1 +=c;
                a[c-'a']--;
            }
        }
        return s1+s2;
    }
};
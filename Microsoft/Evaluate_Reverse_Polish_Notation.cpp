/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

*/




#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int>stk;
       for(auto s : tokens){
           if( s == "+" || s == "-" || s == "*" || s == "/"){
               int op2 = stk.top();
               stk.pop();
               int op1 = stk.top();
               stk.pop();
               if(s == "+"){
                   stk.push(op1 + op2);
               }
               if(s == "-"){
                   stk.push(op1 - op2);
               }
               if(s == "*"){
                   stk.push(op1 * op2);
               }
               if(s == "/"){
                   stk.push(op1 / op2);
               }


           }
           else{
               stringstream ss(s);
               int n;
               ss >> n;
               stk.push(n);

           }
       }
       return stk.top();
    }
};
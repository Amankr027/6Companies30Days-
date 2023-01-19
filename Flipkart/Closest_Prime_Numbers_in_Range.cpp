/*
Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= nums1 < nums2 <= right .
nums1 and nums2 are both prime numbers.
nums2 - nums1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [nums1, nums2]. If there are multiple pairs satisfying these conditions, return the one with the minimum nums1 value or [-1, -1] if such numbers do not exist.

A number greater than 1 is called prime if it is only divisible by 1 and itself.

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prime;
    void SieveOfEratosthenes(int n){

        for(int p=2; p*p <= n ; p++ ){
            if(prime[p] == true){
                for(int i= p*p; i<=n ; i +=p){
                    prime[i] = false;
                }
            }
        }
    }


    vector<int> closestPrimes(int left, int right) {
        prime.resize(right+1 , 1);

        SieveOfEratosthenes(right+1);

        prime[0]=0;
        prime[1]=0;

        int prv = -1;
        int ans = INT_MAX;
        vector<int> rans(2,-1);

        for(int p = left ; p<= right; p++){
            if(prime[p]){
                if(prv == -1){
                    prv  = p;
                }
                else if(p - prv < ans){
                    rans[0]=prv;
                    rans[1] = p;
                    ans = p - prv;
                }
                prv = p;
            }
        }
        return rans;
    }
};
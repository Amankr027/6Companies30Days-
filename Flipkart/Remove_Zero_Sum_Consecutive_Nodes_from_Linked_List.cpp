/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
*/
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == NULL){
            return 0;
        }

        unordered_map<int , ListNode*> mp;
        ListNode*dummy = new ListNode(0);

        dummy->next=head;
        mp[0]=dummy;

        int ps = 0;

        while(head != NULL){
            ps += head->val;
            if(mp.find(ps)!=mp.end()){
                    ListNode*start = mp[ps];
                    int sum =ps;
                    while(start != NULL && start != head){
                        start = start->next;
                        sum += start->val;
                        if(start!=head){
                            mp.erase(sum);
                        }
                    }
                      mp[ps]->next = head->next;

            }
            else{
                mp[ps] = head;
            }

            head = head->next;
        }
         return dummy->next;
    }
};
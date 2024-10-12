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
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head || !head -> next || k == 0) return head;
        
       int len = 1;
        
       ListNode *tail = head;
        
        while(tail -> next) {
           tail = tail -> next;
           len++;
        }
        
        k = k % len;
        
        if(k == 0) return head;
        
        tail -> next = head;
        
        int val = len - k;
        
        int count = 1;
        ListNode *temp = head;
        
        while(count < val) {
           temp = temp -> next;
           count++;
        }
        
        ListNode *newHead = temp -> next;
        temp -> next = NULL;
        
        return newHead;
    }
};
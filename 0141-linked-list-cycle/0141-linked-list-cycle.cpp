/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(!head || !head -> next) return false;
       if(head == head -> next) return true;
        
       ListNode *slow = head;
       ListNode *fast = head -> next;
        
       while(fast) {
         slow = slow -> next;
         fast = fast -> next;
         if(fast) fast = fast -> next;
           
         if(slow == fast) return true;
       }
        
       return false;
    }
};
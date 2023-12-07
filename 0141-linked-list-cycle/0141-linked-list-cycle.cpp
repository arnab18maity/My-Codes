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
      if(!head) return false;
      ListNode *fast = head -> next;
      ListNode *slow = head;
      
      while(fast != NULL) {
         if(slow == fast) return true;
         slow = slow -> next;
         fast = fast -> next;
         if(fast) fast = fast -> next;
      }
        
      return false;
    }
};
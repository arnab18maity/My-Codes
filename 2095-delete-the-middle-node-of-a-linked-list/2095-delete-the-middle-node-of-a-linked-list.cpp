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
    ListNode* deleteMiddle(ListNode* head) {
       if(!head || !head -> next) return NULL;
        
       ListNode *fast = head -> next, *slow = head;
        
       while(fast -> next && fast -> next -> next) {
          slow = slow -> next;
          fast = fast -> next -> next;
       } 
        
        ListNode *del = slow -> next;
        slow -> next = slow -> next -> next;
        
        delete(del);
        
        return head;
    }
};
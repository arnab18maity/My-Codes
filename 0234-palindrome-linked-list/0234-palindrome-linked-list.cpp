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
    ListNode *reverseLL(ListNode *head){
        if(!head || !head -> next){
            return head;
        }
        
        ListNode *newHead = reverseLL(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
     if(!head || !head -> next) return true;
        
      ListNode *slow = head, *fast = head -> next;
      
      while(fast -> next != NULL) {
          slow = slow -> next;
          fast = fast -> next;
          if(fast -> next){
              fast = fast -> next;
          }
      }
        
      ListNode *head2 = reverseLL(slow -> next);
        
      ListNode *temp1 = head, *temp2 = head2;
      
        while(temp1 && temp2)
        {
            if(temp1 -> val == temp2 -> val){
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            else{
                return false;
            }
        }
        
        return true;
      
    }
};


















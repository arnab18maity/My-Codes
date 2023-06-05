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
    ListNode* reverseList(ListNode *head)
    {
        if(!head || !head -> next)
        {
            return head;
        }
        
      ListNode *newHead = reverseList(head -> next);
      head -> next -> next = head;
      head -> next = NULL;
      return newHead; 
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(!l1 && !l2)
      {
          return NULL;
      }
        
       int v1 = 0, v2 = 0, carry = 0, sum = 0;
        
       ListNode *head = NULL;
        
        while(l1 != NULL || l2 != NULL)
        {
          v1 = 0, v2 = 0, sum = 0;
            
          if(l1){
            v1 = l1 -> val; 
          }
            
          if(l2){
            v2 = l2 -> val;
          } 
            
          sum = v1 + v2 + carry;
          carry = sum / 10; 
          int value = sum % 10;
          ListNode *newNode = new ListNode(value,NULL);
            
          if(head == NULL){
             head = newNode;
          }
          else{  
           newNode -> next = head;
           head = newNode;
          }
            
          if(l1 != NULL) {
           l1 = l1 -> next;
          }
          if(l2 != NULL) {
           l2 = l2 -> next;
          }
        }
        
        if(carry != 0)
        {
          ListNode *newNode = new ListNode(carry,NULL);
          newNode -> next = head;
          head = newNode;
        }
        
      ListNode *newHead = reverseList(head);
        
      return newHead;
    }
};
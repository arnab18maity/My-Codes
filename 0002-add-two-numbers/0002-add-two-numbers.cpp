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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(!l1 && !l2)
      {
          return NULL;
      }
        
       int v1 = 0, v2 = 0, carry = 0, sum = 0;
        
       ListNode *head = NULL,*tail = NULL;
        
        while(l1 != NULL || l2 != NULL || carry != 0)
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
          ListNode *newNode = new ListNode(sum % 10,NULL);
            
          if(head == NULL){
             head = newNode;
             tail = newNode;
          }
            
          else{  
            tail -> next = newNode;
            tail = newNode;
          }
            
          if(l1 != NULL) {
            l1 = l1 -> next;
          }
            
          if(l2 != NULL) {
            l2 = l2 -> next;
          }
      }
        
      return head;
    }
};
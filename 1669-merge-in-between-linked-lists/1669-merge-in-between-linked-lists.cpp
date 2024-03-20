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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
       ListNode *temp1 = list1, *temp2 = list2;
       ListNode *Aprev,*Anode,*Bnode;
       int count = 0;
        
       while(temp1) {
         if(count == a-1) Aprev = temp1;
         if(count == a) Anode = temp1;
         if(count == b) Bnode = temp1;
           
         temp1 = temp1 -> next;
         count++;
       }
        
       Aprev -> next = list2;
       
       while(temp2 -> next) {
          temp2 = temp2 -> next;
       }
        
       temp2 -> next = Bnode -> next;
       Bnode -> next = NULL;
       
       ListNode *temp3 = Anode;
       while(temp3) {
          ListNode *del = temp3;
          temp3 = temp3 -> next;
          delete(del);
       }
        
       return list1;
    }
};
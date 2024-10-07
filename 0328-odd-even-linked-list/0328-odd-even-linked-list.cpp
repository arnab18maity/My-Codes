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
    ListNode* oddEvenList(ListNode* head) {
//        ListNode *oddHead = NULL, *oddTail = NULL;
//        ListNode *evenHead = NULL, *evenTail = NULL;
//        int index = 1;
         
//        ListNode *temp = head;
        
//        while(temp) {
//          if(index & 1) {
//                if(oddHead == NULL) {
//                  oddHead = temp;
//                  oddTail = temp;
//                } 
//                else{
//                  oddTail -> next = temp;
//                  oddTail = temp;
//                }
//          }
//          else{
//               if(evenHead == NULL) {
//                  evenHead = temp;
//                  evenTail = temp;
//               }
//               else{
//                   evenTail -> next = temp;
//                   evenTail = temp;
//               }
               
//          }
           
//          index++;
//          temp = temp -> next;
//        }
        
//        if(oddTail) oddTail -> next = evenHead;
//        if(evenTail) evenTail -> next = NULL;
        
//        return oddHead;
        
       if(!head || !head -> next) return head;
       ListNode *odd = head, *even = head -> next, *evenHead = head -> next;
       
       while(even && even -> next) {
          odd -> next = odd -> next -> next;
          even -> next = even -> next -> next;
           
          odd = odd -> next;
          even = even -> next;
       }
        
       odd -> next = evenHead;
        
       return head;
       
    }
};
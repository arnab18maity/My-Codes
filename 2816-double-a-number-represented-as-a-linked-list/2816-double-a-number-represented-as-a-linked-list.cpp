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
        if(!head || !head -> next) return head;
        
        ListNode *newHead = reverseLL(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return newHead;
    }
    
    ListNode* doubleIt(ListNode* head) {
        if(!head) return head;
        
        ListNode *Head = reverseLL(head);
        
        ListNode *newHead = NULL,*newTail = NULL,*temp = Head;
        int carry = 0;
        
        while(temp || carry != 0)
        {
            int sum = carry;
            if(temp){
                sum += temp -> val * 2;
            }
            
            ListNode *newNode = new ListNode(sum%10,NULL);
            carry = sum/10;
            
            if(newHead == NULL){
                newHead = newNode;
            }
            else{
                newNode -> next = newHead;
                newHead = newNode;
            }
            
           if(temp) temp = temp -> next;
            
        }
        
         return newHead;
    }
    
};
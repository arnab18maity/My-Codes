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
    ListNode *reverse(ListNode *head) {
       if(!head || !head -> next) return head;
       ListNode *prev = NULL, *curr = head;
        
        while(curr) {
           ListNode *temp = curr -> next;
           curr -> next = prev;
           prev = curr;
           curr = temp;
        }
        
        return prev;
    }
    
    int size(ListNode *head) {
       if(!head) return 0;
       ListNode *curr = head;
       int count = 0;
       
       while(curr) {
         count++;
         curr = curr -> next;
       }
        
       return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next || k == 0) return head;
        
        int s = size(head);
        
        k = k % s;
        
        if(k == 0) return head;
        
        ListNode *newHead = reverse(head);
        int count = 1;
        ListNode *temp = newHead;
        
        while(count < k) {
           temp = temp -> next;
           count++;
        }
        
        ListNode *rightPart = temp -> next;
        temp -> next = NULL;
        
        ListNode *leftHead = reverse(newHead);
        ListNode *rightHead = reverse(rightPart);
        
        temp = leftHead;
        
        while(temp -> next) temp = temp -> next;
        
        temp -> next = rightHead;
        
        return leftHead;
    }
};
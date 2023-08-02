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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr = head -> next;
        ListNode *tail = head -> next;
        ListNode *newHead = NULL;
        ListNode *newTail = NULL;
        int sum = 0;
        
        while(tail != NULL)
        {
            sum = 0;
            while(tail -> val != 0){
                sum += tail -> val;
                tail = tail -> next;
            }
            
            ListNode *newNode = new ListNode(sum,NULL);
            if(newHead == NULL){
                newHead = newNode;
                newTail = newNode;
            }
            else{
                newTail -> next = newNode;
                newTail = newNode;
            }
            
            curr = tail -> next;
            tail = tail -> next;
        }
        
        return newHead;
    }
};
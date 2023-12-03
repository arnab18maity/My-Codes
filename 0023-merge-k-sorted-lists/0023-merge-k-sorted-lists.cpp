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
    ListNode *merge(ListNode *first, ListNode *second) {
        if(!first) return second;
        if(!second) return first;
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        
        while(first && second) {
            if(first -> val <= second -> val) {
                temp -> next = first;
                temp = temp->next;
                first = first -> next;
            }
            else{
                temp -> next = second;
                temp = temp -> next;
                second = second -> next;
            }
        }
        
       if(first) temp -> next = first;
       else temp -> next = second;
        
      return dummy -> next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        
        ListNode* head = lists[0];
        
        for (int i = 1; i < lists.size(); i++) {
            head = merge(head, lists[i]);
        }
        
        return head;
    }
};






















//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  private:
    Node *reverseList(Node *head) {
       if(!head || !head -> next) return head;
       
       Node *newHead = reverseList(head -> next);
       
       head -> next -> next = head;
       head -> next = NULL;
       
       return newHead;
    }
    
  public:
    Node* addOne(Node* head) {
       Node *newHead = reverseList(head);
       
       Node *curr = newHead, *prev = NULL;
       int rem = 0; 
       
       while(curr || rem) {
          if(curr) {
            int n = curr -> data + rem;
            if(curr == newHead) n += 1;
            int val = n % 10;
            curr -> data = val;
            rem = n / 10;
            prev = curr;
            curr = curr -> next;
          } 
          else{
            Node *newNode = new Node(rem);
            prev -> next = newNode;
            break;
          }
       }
       
       newHead = reverseList(newHead);
       
       return newHead;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
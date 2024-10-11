//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int bfs(Node *root, map<Node*,Node*> parentMap) {
        map<Node*,int> vis;
        vis[root] = 1;
        
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        int reqTime = 0;
        
        while(!q.empty()) {
          auto it = q.front();
          q.pop();
          Node *curr = it.first;
          int currTime = it.second;
          bool flag = false;
          
          if(curr -> left && vis.find(curr -> left) == vis.end()) {
              flag = true;
              q.push({curr -> left, currTime+1});
              vis[curr -> left] = 1;
          }
          
          if(curr -> right && vis.find(curr -> right) == vis.end()) {
             flag = true;
             q.push({curr -> right, currTime+1}); 
             vis[curr -> right] = 1;
          }
          
          if(parentMap.find(curr) != parentMap.end() && vis.find(parentMap[curr]) == vis.end()) {
              flag = true;
              q.push({parentMap[curr], currTime+1});
              vis[parentMap[curr]] = 1;
          }
          
          if(flag) reqTime = currTime + 1;
        }
        
        return reqTime;
    }
    
    int minTime(Node* root, int target) 
    {
        Node *bfsRoot;
        map<Node*,Node*> parentMap;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
           Node *curr = q.front();
           q.pop();
           
           if(curr -> data == target) bfsRoot = curr;
           
           if(curr -> left) {
              parentMap[curr -> left] = curr;
              q.push(curr -> left);
           }
           
           if(curr -> right) {
              parentMap[curr -> right] = curr;
              q.push(curr -> right);
           }
        }
        
        int result = bfs(bfsRoot, parentMap);
        
        return result;
    }
    
    
    
    
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
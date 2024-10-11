/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCBT(TreeNode *root) {
       if(!root) return true;
       queue<TreeNode*> q;
       q.push(root);
       bool nullSeen = false;
       
       while(!q.empty()) {
          TreeNode *curr = q.front();
          q.pop();
          
          if(curr == NULL) nullSeen = true;
          
          if(nullSeen && curr) return false;
          
          if(curr) {
            q.push(curr -> left);
            q.push(curr -> right);
          }
       }
       
       return true;
    }
    
    bool isCompleteTree(TreeNode* root) {
       return isCBT(root); 
    }
};
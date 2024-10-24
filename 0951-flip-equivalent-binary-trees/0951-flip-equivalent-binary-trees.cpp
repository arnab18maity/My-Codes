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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
       if(!root1 || !root2) return root1 == root2;
       if(root1 -> val != root2 -> val) return false;
        
       if(root1 -> left && root2 -> left && root1 -> left -> val != root2 -> left -> val) {
           TreeNode *temp = root1 -> left;
           root1 -> left = root1 -> right;
           root1 -> right = temp;
       }
        
       if(root1 -> right && root2 -> right && root1 -> right -> val != root2 -> right -> val) {
           TreeNode *temp = root1 -> left;
           root1 -> left = root1 -> right;
           root1 -> right = temp;
       }
        
        if((root1 -> left && !root2 -> left) || (root1 -> right && !root2 -> right)) {
           TreeNode *temp = root1 -> left;
           root1 -> left = root1 -> right;
           root1 -> right = temp;
        }
          
       return flipEquiv(root1 -> left, root2 -> left) && flipEquiv(root1 -> right, root2 -> right);
    }
};
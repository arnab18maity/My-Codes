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
    
    // int height(TreeNode *root) {
    //   if(!root) return 0;
    //   return 1 + max(height(root -> left), height(root -> right));  
    // }
    
    int height(TreeNode *root) {
      if(!root) return 0;
      
      int lH = height(root -> left);
      if(lH == -1) return -1;
      int rH = height(root -> right);
      if(rH == -1) return -1;
        
      if(abs(rH-lH) > 1) return -1;
        
      return max(lH,rH) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
//        if(!root) return true;
        
//        int lh = 1 + height(root -> left);
//        int rh = 1 + height(root -> right);
        
//        if(abs(lh - rh) > 1) return false;
        
//        bool lRes = isBalanced(root -> left);
//        bool rRes = isBalanced(root -> right);
        
//        return lRes && rRes;
        
        return height(root) != -1;
    }
};
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
    
    int height(TreeNode *root, int &maxi) {
        if(!root) return 0;
        
        int lH = height(root -> left, maxi);
        int rH = height(root -> right, maxi);
      
        maxi = max(maxi, lH + rH);

        return max(lH,rH) + 1; 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
       int maxi = 0;
       height(root, maxi);
       return maxi;
    }
};
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
    int bfs(TreeNode *root, map<TreeNode*,TreeNode*> parentMap) {
        map<TreeNode*,int> vis;
        vis[root] = 1;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        int reqTime = 0;
        
        while(!q.empty()) {
          auto it = q.front();
          q.pop();
          TreeNode *curr = it.first;
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
    
    int amountOfTime(TreeNode* root, int start) {
        TreeNode *bfsRoot;
        map<TreeNode*,TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
           TreeNode *curr = q.front();
           q.pop();
           
           if(curr -> val == start) bfsRoot = curr;
           
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
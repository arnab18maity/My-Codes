class Solution {
public:
    
    vector<vector<int>> combinations;
    
    void solve(int ind, int target, vector<int>& candidates, vector<int> &ans) {
       if(ind >= candidates.size()) {
          if(target == 0) {
              combinations.push_back(ans);
          }
           
           return;
       }
        
       if(target == 0) {
          combinations.push_back(ans);
          return;
       }
        
       if(candidates[ind] <= target) {
          ans.push_back(candidates[ind]);
          solve(ind, target - candidates[ind], candidates, ans);
          ans.pop_back();
       }
        
       solve(ind+1, target, candidates, ans);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> ans;
       
       solve(0,target, candidates, ans);
        
       return combinations;
    }
};
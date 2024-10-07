class Solution {
public:
    void solve(int ind, int target, vector<int>& candidates, set<vector<int>> &st, vector<int> &ans) {
       if(ind >= candidates.size()) return;
       if(target == 0) {
          st.insert(ans);
          return;
       }
        
       if(candidates[ind] <= target) {
          ans.push_back(candidates[ind]);
          solve(ind, target - candidates[ind], candidates, st, ans);
          ans.pop_back();
       }
        
       solve(ind+1, target, candidates, st, ans);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       set<vector<int>> st;
       vector<int> ans;
       vector<vector<int>> combinations;
       
       solve(0,target, candidates, st, ans);
        
       for(auto it : st) {
          combinations.push_back(it);
       }
        
       return combinations;
    }
};
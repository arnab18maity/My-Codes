class Solution {
public:
    vector<vector<int>> combinations;
    // set<vector<int>> st;
    
    void solve(int ind, int target, vector<int>& candidates, vector<int> &ans) {
       if(target == 0) {
          combinations.push_back(ans);
          return;
       }
        
       for(int i = ind; i < candidates.size(); i++) {
           if(i > ind && candidates[i] == candidates[i-1]) continue;
           if(candidates[i] > target) break;
           
           ans.push_back(candidates[i]);
           solve(i+1, target - candidates[i], candidates, ans);
           ans.pop_back();
       }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       if(candidates.size() == 0) return combinations;
        
       sort(candidates.begin(), candidates.end());
        
       vector<int> ans;
        
       solve(0, target, candidates, ans);
        
       // for(auto it : st) {
       //    combinations.push_back(it);
       // }
        
       return combinations;
    }
};
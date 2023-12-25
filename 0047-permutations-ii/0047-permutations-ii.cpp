class Solution {
public:
     void helper(int i, vector<int>& nums, vector<vector<int>> &ans, set<vector<int>>& st) {
        if(i == nums.size()) {
           if(st.find(nums) != st.end()) return;
            
           ans.push_back(nums);
           st.insert(nums);
           return;
        }
        
        for(int j = i; j < nums.size(); j++) {
           swap(nums[i],nums[j]);
           helper(i+1,nums,ans,st);
           swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> ans;
       set<vector<int>> st;
       helper(0,nums,ans, st);
       return ans;
    }
};
class Solution {
public:
     void helper(int i, vector<int>& nums, vector<vector<int>> &ans) {
        if(i == nums.size()) {
           ans.push_back(nums);
           return;
        }
         
        set<int> st;
        
        for(int j = i; j < nums.size(); j++) {
           // If an element is already visited no need to recompute
           if(st.find(nums[j]) != st.end()) continue;
            
           st.insert(nums[j]);
           swap(nums[i],nums[j]);
           helper(i+1,nums,ans);
           swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> ans;
       helper(0,nums,ans);
       return ans;
    }
};
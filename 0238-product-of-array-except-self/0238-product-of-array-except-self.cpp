class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int suffix = 1, prefix = 1;
        vector<int> ans(nums.size(), 1);
        
        for(int i = 0; i < nums.size(); i++) {
            ans[i] *= prefix;
            prefix *= nums[i];
        }
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        
        return ans;
    }
};
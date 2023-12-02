class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int suffix = 1, prefix = 1;
        vector<int> ans(nums.size(), 1);
        
        // Product of Array Except Self = Prefix_Product * Suffix_Product
        
        // Storing the prefix product while forward iteration
        for(int i = 0; i < nums.size(); i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }
        
        // Multiplying the suffix product while backward iteration
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        
        return ans;
    }
};
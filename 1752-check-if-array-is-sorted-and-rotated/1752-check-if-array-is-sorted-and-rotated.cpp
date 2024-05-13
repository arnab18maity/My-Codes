class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), count = 0;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1]){
               count++; 
            } 
        }
        
        // Compare the last & fast element as the array can be rotated
        if(nums[0] < nums[n-1]) count++;
        
        return count <= 1;
    }
};
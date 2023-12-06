class Solution {
public:
   /*
    bool f(int ind, vector<int> &nums, vector<int> &dp) {
       if(ind == nums.size() - 1) return true;
       if(nums[ind] == 0) return false;
        
       if(dp[ind] != -1) return dp[ind];
       
       for(int i = 1; i <= nums[ind]; i++) {
           bool res = f(ind+i,nums,dp);
           if(res) return dp[ind] = true;
       } 
       
        return dp[ind] = false;
    }
   */ 
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      vector<int>dp(n,0);
      dp[n-1] = true;
        
      for(int ind = n-2; ind >= 0; ind--) {
        for(int i = 1; i <= nums[ind]; i++) {
           bool res = dp[ind+i];
           if(res) {
             dp[ind] = true;
             break;
           }
       }   
      }
        
      return dp[0];
    }
};
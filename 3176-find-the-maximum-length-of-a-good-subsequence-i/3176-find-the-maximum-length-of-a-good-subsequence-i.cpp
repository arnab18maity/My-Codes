class Solution {
public:
    int helper(int ind, vector<int> &nums, int rem, int prev, vector<vector<vector<int>>> &dp) {
       if(ind < 0) return 0;
        
       if(dp[ind][prev][rem] != -1) return dp[ind][prev][rem];
        
       int take = 0;
        
       int notTake = helper(ind-1,nums,rem,prev,dp);
       
       if(prev == nums.size() || nums[ind] == nums[prev]) {
          take = 1 + helper(ind-1,nums,rem,ind,dp);
       }
        
       if(prev != nums.size() && nums[ind] != nums[prev] && rem > 0) {
          take = 1 + helper(ind-1,nums,rem-1,ind,dp);
       }
           
        
       return dp[ind][prev][rem] = max(take,notTake);
       
    }
    
    int maximumLength(vector<int>& nums, int k) {
       int n = nums.size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        
       return helper(n-1,nums,k,n,dp); 
    }
};
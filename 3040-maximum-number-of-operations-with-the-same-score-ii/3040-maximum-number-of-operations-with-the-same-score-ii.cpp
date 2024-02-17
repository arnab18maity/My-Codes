class Solution {
public:
    int func(int sum, vector<int>& nums, int first, int last, vector<vector<int>>& dp) {
        if(first >= last) return 0;
        
        if(dp[first][last] != -1) return dp[first][last];
             
        int res1 = 0, res2 = 0, res3 = 0;
        
        int sf2 = nums[first] + nums[first+1];
        if(sf2 == sum) res1 = 1 + func(sum, nums, first+2,last,dp);
            
        int sl2 = nums[last] + nums[last-1];
        if(sl2 == sum) res2 = 1 + func(sum, nums, first, last-2,dp);
            
        int sfl = nums[first] + nums[last];
        if(sfl == sum) res3 = 1 + func(sum, nums, first+1, last-1,dp);
        
        return dp[first][last] = max({res1,res2,res3});
    }
    
    int maxOperations(vector<int>& nums) {
      int n = nums.size();
      if(n == 2) return 1;
        
      int sumOfFirstTwo = nums[0] + nums[1];
      int sumOfLastTwo = nums[n-1] + nums[n-2];
      int sum0fFirstAndLast = nums[0] + nums[n-1];
        
      vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
      vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
      vector<vector<int>>dp3(n+1,vector<int>(n+1,-1));
      
      int res1 = 1 + func(sumOfFirstTwo, nums, 2, n-1,dp1);
      int res2 = 1 + func(sumOfLastTwo, nums, 0, n-3, dp2);
      int res3 = 1 + func(sum0fFirstAndLast, nums, 1, n-2, dp3);
     
      return max({res1,res2,res3});
    }
};
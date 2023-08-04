class Solution {
public:
    int solve(int n,vector<int> &dp){
        
        
        if(n == 1){
            return 1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
        
        
    }
    
    int climbStairs(int n) {       
      if(n == 0){
            return 1;
        }
        
       int curr = 1;
       int prv  = 1;
       int ans  = 1;
       for(int i = 2; i <= n ; i++){
           ans = prv + curr;
           prv = curr;
           curr = ans;
       }
        
      return ans;
    }
};
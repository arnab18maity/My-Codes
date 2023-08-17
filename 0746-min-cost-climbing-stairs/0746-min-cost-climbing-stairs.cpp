class Solution {
public:
 /*
    int solve(int n, vector<int> &cost,vector<int> &dp){
        if(n == 0){
            return cost[n];
        }
        
        if(n == -1){
          return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int ans1 = INT_MAX,ans2 = INT_MAX;
        
        ans1 = cost[n] + solve(n-1,cost,dp);
        if(n > 0) ans2 = cost[n] + solve(n-2,cost,dp);
        
        return dp[n] = min(ans1,ans2);
    }
 */

/*
int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        dp[0] = cost[0];
        
        for(int i = 1; i < n; i++){
            if(i < 2){ 
              dp[i] = cost[i];  //We can start from 0th or 1th Index
            }
            else{
               dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
            }
        }
        
        
        return min(dp[n-1],dp[n-2]);
    }
};
*/

int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev1 = cost[1], prev2 = cost[0];
        
        for(int i = 2; i < n; i++){
           int curri = cost[i] + min(prev1,prev2);
           prev2 = prev1;
           prev1 = curri;
        }
        
        
        return min(prev1,prev2);
    }
};



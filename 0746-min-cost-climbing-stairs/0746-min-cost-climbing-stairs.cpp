class Solution {
public:
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
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        int ans1 = solve(n-1,cost,dp);
        int ans2 = solve(n-2,cost,dp);
        
        return min(ans1,ans2);
    }
};
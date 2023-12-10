class Solution {
public:
 /*
    int f(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp) {
       if(amount == 0) return 0;
       if(ind == 0) {
          if(amount % coins[0] == 0) return amount/coins[0];
           
          return 1e9;
       }
        
       if(dp[ind][amount] != -1) return dp[ind][amount];
        
       int notTake = 0 + f(ind-1,coins,amount,dp);
       int take = 1e9;
       if(coins[ind] <= amount) take = 1 + f(ind,coins,amount-coins[ind],dp);
        
       return dp[ind][amount] = min(take,notTake);
    }
*/    
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<vector<int>> dp(n,vector<int>(amount+1,0));
       
       for(int amt = 1; amt <= amount; amt++) {
           if(amt % coins[0] == 0) {
              dp[0][amt] = amt/coins[0];
           }
           else{
              dp[0][amt] = 1e9;
            }
       }
        
       for(int ind = 1; ind < n; ind++) {
         for(int amt = 1; amt <= amount; amt++) {
           int notTake = 0 + dp[ind-1][amt];
           int take = 1e9;
           if(coins[ind] <= amt) take = 1 + dp[ind][amt-coins[ind]];

           dp[ind][amt] = min(take,notTake);
         }
       }
        
       return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
    }
};
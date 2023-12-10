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
       vector<int> prev(amount+1,0), curr(amount+1,0);
        
       for(int amt = 1; amt <= amount; amt++) {
           if(amt % coins[0] == 0) {
              prev[amt] = amt/coins[0];
           }
           else{
              prev[amt] = 1e9;
            }
       }
        
       for(int ind = 1; ind < n; ind++) {
         for(int amt = 1; amt <= amount; amt++) {
           int notTake = 0 + prev[amt];
           int take = 1e9;
           if(coins[ind] <= amt) take = 1 + curr[amt-coins[ind]];

           curr[amt] = min(take,notTake);
         }
           
         prev = curr;
       }
        
       return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};
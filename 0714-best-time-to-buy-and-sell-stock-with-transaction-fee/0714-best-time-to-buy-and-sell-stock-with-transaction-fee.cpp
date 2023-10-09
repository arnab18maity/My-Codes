class Solution {
public:
/*
    int f(int ind,vector<int> &prices, int buy,vector<vector<int>>&dp,int fee) {
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy == 1) {
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,prices,0,dp,fee),
                                      f(ind+1,prices,1,dp,fee));
        }
        
            return dp[ind][buy] = max(prices[ind] - fee + f(ind+1,prices,1,dp,fee),
                                      f(ind+1,prices,0,dp,fee));
    }
*/
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2,0), prev(2,0);
        
        for(int ind = n-1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
               if(buy == 1) {
                  curr[buy] = max(-prices[ind] + prev[0],
                                  prev[1]);
               }
               else{
                  curr[buy] = max(prices[ind] - fee + prev[1],
                                  prev[0]);
               }
            }
         
           prev = curr;
        }
        
        return curr[1];
    }
};
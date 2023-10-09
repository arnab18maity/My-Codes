class Solution {
public:
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
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,prices,1,dp,fee);
    }
};
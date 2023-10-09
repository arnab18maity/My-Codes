class Solution {
public:
    int f(int ind,vector<int> &prices, int tranNo,int buy,vector<vector<int>>&dp) {
        if(ind == prices.size()) return 0;
        if(tranNo == 0) return 0;
        if(dp[ind][tranNo] != -1) return dp[ind][tranNo];
        
        if(buy == 1) {
            return dp[ind][tranNo] = max(-prices[ind] + f(ind+1,prices,tranNo-1,0,dp),
                                      f(ind+1,prices,tranNo,1,dp));
        }
        
        return dp[ind][tranNo] = max(prices[ind] + f(ind+1,prices,tranNo-1,1,dp),
                                  f(ind+1,prices,tranNo,0,dp));
    }
    
    int maxProfit(int k, vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
      return f(0,prices,2*k,1,dp);
    }
};
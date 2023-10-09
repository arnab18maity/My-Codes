class Solution {
public:
  /*
    int f(int ind,vector<int> &prices, int buy,vector<vector<int>>&dp) {
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy == 1) {
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,prices,0,dp),
                                      f(ind+1,prices,1,dp));
        }
        
           return dp[ind][buy] = max(prices[ind] + f(ind+1,prices,1,dp),
                                     f(ind+1,prices,0,dp));
    }
*/
    
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int> curr(2,0), prev(2,0);
        
      for(int ind = n-1; ind >= 0; ind--) {
          for(int buy = 0; buy <= 1; buy++) {
              if(buy == 1) {
                 curr[buy] = max(-prices[ind] + prev[0],
                                    prev[1]);
              }
              else{
                 curr[buy] = max(prices[ind] + prev[1],
                                 prev[0]);
              }
          }
          
          prev = curr;
      }
        
      return curr[1];
    }
};
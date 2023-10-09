class Solution {
public:
 /*
    int f(int ind,vector<int> &prices, int tranNo,vector<vector<int>>&dp) {
        if(ind == prices.size()) return 0;
        if(tranNo == 0) return 0;
        if(dp[ind][tranNo] != -1) return dp[ind][tranNo];
        
        if(tranNo % 2 == 0) {
            return dp[ind][tranNo] = max(-prices[ind] + f(ind+1,prices,tranNo-1,dp),
                                      f(ind+1,prices,tranNo,dp));
        }
        
        return dp[ind][tranNo] = max(prices[ind] + f(ind+1,prices,tranNo-1,dp),
                                  f(ind+1,prices,tranNo,dp));
    }
*/
    
    int maxProfit(int k, vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        
       for(int ind = n-1; ind >= 0; ind--) {
           for(int tranNo = 1; tranNo <= 2*k ; tranNo++) {
               if(tranNo % 2 == 0) {
                 dp[ind][tranNo] = max(-prices[ind] + dp[ind+1][tranNo-1],
                                       dp[ind+1][tranNo]);
               }
               else{
                dp[ind][tranNo] = max(prices[ind] + dp[ind+1][tranNo-1],
                                      dp[ind+1][tranNo]); 
              }
           }
       } 
        
      return dp[0][2*k];
    }
};
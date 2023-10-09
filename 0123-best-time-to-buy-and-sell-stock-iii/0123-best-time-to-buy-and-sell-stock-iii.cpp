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
    
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int> curr(5,0), prev(5,0);
        
       for(int ind = n-1; ind >= 0; ind--) {
           for(int tranNo = 1; tranNo <= 4 ; tranNo++) {
               if(tranNo % 2 == 0) {
                 curr[tranNo] = max(-prices[ind] + prev[tranNo-1],
                                     prev[tranNo]);
               }
               else{
                curr[tranNo] = max(prices[ind] + prev[tranNo-1],
                                   prev[tranNo]); 
              }
           }
           
          prev = curr;
       } 
        
      return prev[4];
    }
};
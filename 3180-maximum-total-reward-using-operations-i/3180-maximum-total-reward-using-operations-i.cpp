class Solution {
public:
    int helper(int ind, int curValue, vector<int> &rewardValues, vector<vector<int>> &dp) {
        if(ind == rewardValues.size()) return 0;
        
        if(dp[ind][curValue] != -1) return dp[ind][curValue];
        
        int notTake = helper(ind+1, curValue, rewardValues,dp);
        
        int take = 0;
        
        if(rewardValues[ind] > curValue) take = rewardValues[ind] + helper(ind+1, rewardValues[ind] + curValue, rewardValues,dp);
        
        return dp[ind][curValue] = max(take,notTake);
    }
    
    int maxTotalReward(vector<int>& rewardValues) {
      sort(rewardValues.begin(), rewardValues.end());
      int n = rewardValues.size();
        
      // vector<vector<int>> dp(n,vector<int>(4000,-1));
      // return helper(0,0,rewardValues,dp);
        
      vector<int> curr(4000, 0), prev(4000, 0);
        
      for(int ind = n-1; ind >= 0; ind--) {
        for(int curValue = 0; curValue < 4000; curValue++) {
            int notTake = prev[curValue];        
            int take = 0;
            if(rewardValues[ind] > curValue) take = rewardValues[ind] + prev[rewardValues[ind] + curValue];
            curr[curValue] = max(take,notTake);
        }  
          
         prev = curr;
      }
        
      return prev[0];   
              
    }
};
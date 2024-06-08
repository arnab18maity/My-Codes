class Solution {
public:
    int helper(int ind, vector<int> &nums, int rem, int prev, vector<vector<vector<int>>> &dp) {
       if(ind < 0) return 0;
        
       if(dp[ind][prev][rem] != -1) return dp[ind][prev][rem];
        
       int take = 0;
        
       int notTake = helper(ind-1,nums,rem,prev,dp);
       
       if(prev == nums.size() || nums[ind] == nums[prev]) {
          take = 1 + helper(ind-1,nums,rem,ind,dp);
       }
        
       if(prev != nums.size() && nums[ind] != nums[prev] && rem > 0) {
          take = 1 + helper(ind-1,nums,rem-1,ind,dp);
       }
           
        
       return dp[ind][prev][rem] = max(take,notTake);
       
    }
    
    int maximumLength(vector<int>& nums, int k) {
       // int n = nums.size();
       // vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
       // return helper(n-1,nums,k,n,dp); 
        
        
//         int n = nums.size(); 
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k+1, 0)));
        
//         for (int ind = 1; ind <= n; ++ind) {
//             for (int prev = 0; prev <= n; ++prev) {
//                 for (int rem = 0; rem <= k; ++rem) {
                    
//                     int notTake = dp[ind-1][prev][rem];
//                     int take = 0;
                    
//                     if(prev == n || nums[ind-1] == nums[prev]) {
//                       take = 1 + dp[ind-1][ind-1][rem];
//                     }

//                     if(prev != n && nums[ind-1] != nums[prev] && rem > 0) {
//                       take = 1 + dp[ind-1][ind-1][rem-1];
//                     }   
                    
//                    dp[ind][prev][rem] = max(take,notTake); 
//                 }
//             }
//         }
        
//         return dp[n][n][k];
        
     int n = nums.size();
     vector<vector<int>> previous(n+1,vector<int>(k+1,0)), curr(n+1,vector<int>(k+1,0));
      
      for (int ind = 1; ind <= n; ++ind) {
        for(int prev = 0; prev <= n; prev++) {
            for(int rem = 0; rem <= k; rem++) {
                    int notTake = previous[prev][rem];
                    int take = 0;
                    
                    if(prev == n || nums[ind-1] == nums[prev]) {
                      take = 1 + previous[ind-1][rem];
                    }

                    if(prev != n && nums[ind-1] != nums[prev] && rem > 0) {
                      take = 1 + previous[ind-1][rem-1];
                    }   
                    
                   curr[prev][rem] = max(take,notTake);
            }
        } 
         previous = curr;  
      }
        
        return previous[n][k];
    }
};
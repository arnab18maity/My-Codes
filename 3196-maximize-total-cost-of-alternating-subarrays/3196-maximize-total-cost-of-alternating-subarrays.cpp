class Solution {
public:
    long long helper(int ind, bool flag, vector<int>& nums, vector<vector<long long>> &dp) {
       if(ind == nums.size()) return 0;
        
       if(dp[ind][flag] != -1) return dp[ind][flag];
        
        // At any Index we have two choice, continue the old subarray or start a new subarray
       // If flag == true, it means we have to take that element with positive sign
      //  if flag == false, it means we have to take that element with negative sign
    
        
       // Continue old subarray
       long long oldCost = 0;
        
       if(flag) {
         oldCost = nums[ind] + helper(ind+1, false, nums, dp);
       }
       else{
         oldCost = -nums[ind] + helper(ind+1, true, nums, dp);   
       }
        
        
       // Start new subarray
       long long newCost = nums[ind] + helper(ind+1, false, nums, dp);
        
       return dp[ind][flag] = max(oldCost,newCost);
    }
    
    long long maximumTotalCost(vector<int>& nums) {
       int n = nums.size();
       // vector<vector<long long>> dp(n, vector<long long>(2,-1));
       // return helper(0, true, nums, dp); 
        
       // vector<vector<long long>> dp(n+1, vector<long long>(2,0));
        
       vector<long long> curr(2,0), prev(2,0);
        
       for(int ind = n-1; ind >= 0; ind--) {
           for(int flag = 0; flag < 2; flag++) {
               long long oldCost = 0;
        
               if(flag) {
                 oldCost = nums[ind] + prev[0];
               }
               else{
                 oldCost = -nums[ind] + prev[1];   
               }

               long long newCost = nums[ind] + prev[0];

               curr[flag] = max(oldCost,newCost);
           }
           
           prev = curr;
       }
              
        return prev[1];    
    }
};





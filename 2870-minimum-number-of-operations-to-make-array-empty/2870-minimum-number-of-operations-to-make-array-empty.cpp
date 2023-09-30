class Solution {
public:
/*
    int solve(int ind,vector<int> &nums, vector<int> &dp) {
        if(ind == nums.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int three = 1e9, two = 1e9;
        
        
        if((nums.size() - (ind+1)) >= 2 && nums[ind] == nums[ind+1] && nums[ind] == nums[ind+2]) {
            three = 1 + solve(ind+3,nums,dp);
        }
        
        if((nums.size() - (ind+1)) >= 1 && nums[ind] == nums[ind+1]) {
            two = 1 + solve(ind+2,nums,dp);
        }
        
        if(ind != nums.size() - 1 && nums[ind] != nums[ind+1]) return 1e9;
        
        return dp[ind] = min(three,two);
        
    }
    
    int minOperations(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       vector<int> dp(n,-1);
       int ans = solve(0, nums,dp);
       if(ans >= 1e9) return -1;
        
       return ans;
    }
*/   
    int minOperations(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n = nums.size();
       vector<int> dp(n,0); 
       if(nums.size() == 0) return 0;
        
       for(int ind = n-1; ind >= 0; ind--){
           int three = 1e9, two = 1e9;
           if((nums.size() - (ind+1)) >= 2 && nums[ind] == nums[ind+1] && nums[ind] == nums[ind+2]) {
             three = 1 + (ind + 3 < n ? dp[ind + 3] : 0);
           }
        
           if((nums.size() - (ind+1)) >= 1 && nums[ind] == nums[ind+1]) {
             two = 1 + (ind + 2 < n ? dp[ind + 2] : 0);
          }
        
           if(ind != nums.size() - 1 && nums[ind] != nums[ind+1]) {
              dp[ind] = 1e9;
              continue;
           }
           
           dp[ind] = min(two,three);
       }
        
       return dp[0] >= 1e9 ? -1 : dp[0];
    }
};




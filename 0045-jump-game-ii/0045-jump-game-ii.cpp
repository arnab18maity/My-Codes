class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        if(arr[0] == n-1) return 1; 
        if(arr[0] == 0) return -1; 
        vector<int> dp(n,0);
        
        for(int ind = n-2; ind >= 0 ; ind--) {
          int ans = 1e8;
            for(int i = 1; i <= arr[ind]; i++)
            {
              int res = 1e8;
              
              if((ind + i) < n) 
                res = 1 + dp[ind+i];
              else {
                res = 1;
                ans = min(ans,res);
                break;
              }
              ans = min(ans,res);
            }
            
            dp[ind] = ans;
        }
        
        return dp[0] == 1e8 ? -1 : dp[0];
        
    }
};
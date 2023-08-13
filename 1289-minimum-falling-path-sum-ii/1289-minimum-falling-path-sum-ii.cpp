class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,int n,vector<vector<int>>& dp){
        if(i == 0 &&(j < n && j >= 0)){
            return grid[i][j];
        }
        
        if(i < 0 || j < 0 || j >= n ){
            return 10e5;
        }
        
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        
       int ans = INT_MAX;
       for(int a = 0 ; a < n ; a++){
          if(a != j) {
           int res = grid[i][j] + solve(i-1,a,grid,n,dp);
           ans = min(ans,res);
          }
       }
        
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i = 0; i < n; i++)
        {
            int ans = solve(n-1,i,grid,n,dp);
            mini = min(ans,mini);
        }
        
        return mini;
    }
};
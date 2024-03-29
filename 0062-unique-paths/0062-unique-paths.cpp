class Solution {
public:
  /*
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
       if(i == m - 1 && j == n - 1){
           return 1;
       }
        
       if(i == m || j == n){
           return 0;
       }
        
        if(dp[i][j] != -1){
           return dp[i][j];
        }
        
       int r = solve(i,j+1,m,n,dp);
       int d = solve(i+1,j,m,n,dp);
        
       return dp[i][j] = r + d;
    }
  */
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1; // copy base case
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                 int up = 0, left = 0;
                 if(i > 0) up = dp[i-1][j];
                 if(j > 0) left = dp[i][j-1];
                    
                 dp[i][j] = up + left;
                }
            }
        }
        
       return dp[m-1][n-1];
    }
};
class Solution {
public:
    /* Memoization Solution
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp) {
           if((i == 0 && j == 0) && grid[i][j] != 1){
               return 1;
           }
        
           if(i < 0 || j < 0){
               return 0;
           }
        
           if(grid[i][j] == 1) {
               return 0;
           }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = solve(i-1,j,grid,dp);
        int left = solve(i,j-1,grid,dp);
        
        return dp[i][j] = up+left;
    }
    */
/*  Tabulation Solution  
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(i == 0 && j == 0){
                  dp[i][j] = 1;
                }
                else {
                int up = 0,left = 0;
                if(obstacleGrid[i][j] != 1) {
                  if(i > 0) up = dp[i-1][j];
                  if(j > 0) left = dp[i][j-1];
                }
                  dp[i][j] = up + left;
              }
                
            }
        }
        
        return dp[m-1][n-1];
    }
};

*/

// Space Optimization Solution

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        vector<int> prev(n,0);
        
        for(int i = 0 ; i < m ; i++){
            vector<int> cur(n,0);
            for(int j = 0; j < n ; j++){
                if(i == 0 && j == 0){
                  cur[j] = 1;
                }
                else {
                int up = 0,left = 0;
                if(obstacleGrid[i][j] != 1) {
                  if(i > 0) up = prev[j];
                  if(j > 0) left = cur[j-1];
                }
                 cur[j] = up + left;
              }
                
            }
          prev = cur;
        }
        
        return prev[n-1];
    }
};



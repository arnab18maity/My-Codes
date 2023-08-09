class Solution {
public:
/*  Memoization Solution

    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
         if(i == 0 && j == 0){
             return grid[i][j];
         }
        
         if(i < 0 || j < 0){
             return 201;
         }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + solve(i-1,j,grid,dp);
        int left = grid[i][j] + solve(i,j-1,grid,dp);
        
        return dp[i][j] = min(up,left);
    }
*/ 

/*  Tabulation Solution

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
               if(i == 0 && j == 0){
                   dp[i][j] = grid[i][j];
               } 
               else{
                 int up = 201,left = 201;
                 if(i > 0) up = grid[i][j] + dp[i-1][j];
                 if(j > 0) left = grid[i][j] + dp[i][j-1];
                 
                 dp[i][j] = min(up,left);
               }
            }
        }
        
        return dp[m-1][n-1];
    }
};

*/
    // Space Optimization

int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
       vector<int>prev(n,0);
        
        for(int i = 0; i < m ; i++){
            vector<int> curr(n,0);
            for(int j = 0 ; j < n ; j++){
               if(i == 0 && j == 0){
                   curr[j] = grid[i][j];
               } 
               else{
                 int up = 201,left = 201;
                 if(i > 0) up = grid[i][j] + prev[j];
                 if(j > 0) left = grid[i][j] + curr[j-1];
                 
                 curr[j] = min(up,left);
               }
            }
            
            prev = curr;
        }
        
        return prev[n-1];
    }
};
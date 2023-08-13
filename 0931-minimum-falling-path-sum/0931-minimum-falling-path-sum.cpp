class Solution {
public:
/*
     Memoization Solution

    int solve(int i,int j,vector<vector<int>>& matrix,int n,vector<vector<int>>& dp) {
        if(i == 0 && (j >= 0 && j < n)){
            return matrix[i][j];
        }
        
        if(i < 0 || j < 0 || j >= n ){
            return 10e5;
        }
        
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        
        int up = matrix[i][j] + solve(i-1,j,matrix,n,dp);
        int lDiagonal = matrix[i][j] + solve(i-1,j-1,matrix,n,dp);
        int rDiagonal = matrix[i][j] + solve(i-1,j+1,matrix,n,dp);
        
        return dp[i][j] = min(up,min(lDiagonal,rDiagonal));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i = 0; i < n ; i++)
        {
            int ans = solve(n-1,i,matrix,n,dp);
            mini = min(ans,mini);
        }
        
        return mini;
    }
};
*/
/*
    Tabulation Solution
    
     int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
         
        vector<vector<int>> dp(n,vector<int>(n,0));
         
        for(int j = 0; j < n ; j++)
        {
           dp[0][j] = matrix[0][j];
        } 
         
        for(int i = 1; i < n ; i++)
        {
           for(int j = 0; j < n; j++) {
               int up = INT_MAX;
               int lD = INT_MAX;
               int rD = INT_MAX;
                up = matrix[i][j] + dp[i-1][j];    
                if(j > 0) lD = matrix[i][j] + dp[i-1][j-1];   
                if(j < n-1) rD = matrix[i][j] + dp[i-1][j+1];
        
               dp[i][j] = min(up,min(lD,rD));
           }
        }
         
        int mini = dp[n-1][0];
         
        for(int j = 1; j < n ; j++)
        {
           mini = min(dp[n-1][j],mini);
        } 
        
        return mini;
    }
};

*/
     // Space Optimization
    
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
         
       vector<int> dp(n,0);
         
        for(int j = 0; j < n ; j++)
        {
           dp[j] = matrix[0][j];
        } 
         
        for(int i = 1; i < n ; i++)
        {
           vector<int> curr(n,0);
           for(int j = 0; j < n; j++) {
               int up = INT_MAX;
               int lD = INT_MAX;
               int rD = INT_MAX;
                up = matrix[i][j] + dp[j];    
                if(j > 0) lD = matrix[i][j] + dp[j-1];   
                if(j < n-1) rD = matrix[i][j] + dp[j+1];
        
               curr[j] = min(up,min(lD,rD));
           }
            
            dp = curr;
        }
         
        int mini = dp[0];
         
        for(int j = 1; j < n ; j++)
        {
           mini = min(dp[j],mini);
        } 
        
        return mini;
    }
};
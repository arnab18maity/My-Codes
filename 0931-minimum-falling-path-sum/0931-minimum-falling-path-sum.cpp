class Solution {
public:
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
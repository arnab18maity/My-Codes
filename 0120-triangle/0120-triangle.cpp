class Solution {
public:
    int solve(int i,int j,int row,vector<vector<int>> &triangle,vector<vector<int>>& dp)
    {
        if(i == row) return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + solve(i+1,j,row,triangle,dp);
        int diagonal = triangle[i][j] + solve(i+1,j+1,row,triangle,dp);
        
        return dp[i][j] = min(down,diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,-1));
        return solve(0,0,row-1,triangle,dp);
    }
};
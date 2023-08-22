class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<char>>& matrix, int &maxi, vector<vector<int>> &dp) {
        if(i < 0 || j < 0 || j >= n) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = solve(i,j-1,m,n,matrix,maxi,dp);
        int up = solve(i-1,j,m,n,matrix,maxi,dp);
        int diagonal = solve(i-1,j-1,m,n,matrix,maxi,dp);
        
        if(matrix[i][j] == '1') {
            int ans = 1 + min(left,min(up,diagonal));
            maxi = max(ans,maxi);
            return dp[i][j] = ans;
        }
        
       return dp[i][j] = 0;
            
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        int maxi = 0;
        int s = solve(m-1,n-1,m,n,matrix,maxi,dp);
        
        return maxi * maxi;       
    }
};
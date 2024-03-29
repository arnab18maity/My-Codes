class Solution {
public:
/*
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
*/    
    
     int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        //vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> prev(n,0), curr(n,0);
        int maxi = 0;
        
        for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++) {
              
            int left = j > 0 ? curr[j-1] : 0;
            int up = prev[j];
            int diagonal = j > 0 ? prev[j-1] : 0;

            if(matrix[i][j] == '1') {
                int ans = 1 + min(left,min(up,diagonal));
                maxi = max(ans,maxi);
                curr[j] = ans;
            }
            else{
               curr[j] = 0; 
            }
          }
            
          prev = curr;
        }
        
        return maxi * maxi;       
    }
    
    
    
};






































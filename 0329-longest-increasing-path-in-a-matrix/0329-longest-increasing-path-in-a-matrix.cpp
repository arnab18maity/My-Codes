class Solution {
public:
    int solve(int i, int j,int m,int n,vector<vector<int>>& matrix,int last,vector<vector<int>>& dp) {
        if(i < 0 || i >= m || j < 0 || j >= n){
            return  0;
        }
        
        if(matrix[i][j] <= last) {
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int up = 1 + solve(i-1,j,m,n,matrix,matrix[i][j],dp);
        int down = 1 + solve(i+1,j,m,n,matrix,matrix[i][j],dp);
        int left = 1 + solve(i,j-1,m,n,matrix,matrix[i][j],dp);
        int right = 1 + solve(i,j+1,m,n,matrix,matrix[i][j],dp);
            
       return dp[i][j] = max(up,max(down,max(left,right)));       
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = 1;
        

      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
           int up = 1 + solve(i-1,j,m,n,matrix,matrix[i][j],dp);
           int down = 1 + solve(i+1,j,m,n,matrix,matrix[i][j],dp);
           int left = 1 + solve(i,j-1,m,n,matrix,matrix[i][j],dp);
           int right = 1 + solve(i,j+1,m,n,matrix,matrix[i][j],dp);
            
           ans = max(ans,max(up,max(down,max(left,right)))); 
        }
      }
      
        /*
        i = m-1;
        for(int j = 0; j < n; j++){
           int up = 1 + solve(i-1,j,m,n,matrix,matrix[i][j],dp);
           int down = 1 + solve(i+1,j,m,n,matrix,matrix[i][j],dp);
           int left = 1 + solve(i,j-1,m,n,matrix,matrix[i][j],dp);
           int right = 1 + solve(i,j+1,m,n,matrix,matrix[i][j],dp);
            
           ans = max(ans,max(up,max(down,max(left,right)))); 
        }
        */
        
        return ans;
    }
};
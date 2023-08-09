class Solution {
public:
  /*
     Memoization Solution
   
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

*/

/*
     Tabulation Solution

int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,0));
    
        for(int j = 0; j < row; j++){
            dp[row-1][j] = triangle[row-1][j];
        }
    
        for(int i = row - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                  int down = triangle[i][j] + dp[i+1][j];
                  int diagonal = triangle[i][j] + dp[i+1][j+1];
                    
                  dp[i][j] = min(down,diagonal);
            }
        }
    
        return dp[0][0];
    }
};

*/
   // Space Optimization  
    
 int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int>prev(row,0);
    
        for(int j = 0; j < row; j++){
            prev[j] = triangle[row-1][j];
        }
    
        for(int i = row - 2; i >= 0; i--){
             vector<int> curr(row,0);
            for(int j = i; j >= 0; j--){
                  int down = triangle[i][j] + prev[j];
                  int diagonal = triangle[i][j] + prev[j+1];
                    
                  curr[j] = min(down,diagonal);
            }
            
            prev = curr;
        }
    
        return prev[0];
    }
};   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    




































    
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
       if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0) return 0;
       
       int score = grid[i][j];
       grid[i][j] = -grid[i][j]; // Making it negative to identify as visited
       
       score += max({dfs(i-1,j,grid),dfs(i+1,j,grid),dfs(i,j-1,grid),dfs(i,j+1,grid)});
           
       grid[i][j] = -grid[i][j]; // Making it positive while backtracking
        
       return score;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) continue;
                else{
                  maxi = max(maxi,dfs(i,j,grid));
                }
            }
        }
        
        return maxi;
    }
};
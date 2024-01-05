class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
         int n = grid.size();
         int m = grid[0].size();
         vis[row][col] = 1;
         queue<pair<int,int>> q;
         q.push({row,col});
         
         while(!q.empty()) {
           int r = q.front().first;
           int c = q.front().second;
           q.pop();
           int delRow[] = {-1,0,1,0};
           int delCol[] = {0,1,0,-1};
             
           for(int i = 0; i < 4; i++) {
              int newR = r + delRow[i];
              int newC = c + delCol[i];
              if(newR >= 0 && newR < n && newC >= 0 && newC < m
                && !vis[newR][newC] && grid[newR][newC] == '1') {
                 vis[newR][newC] = 1;
                 q.push({newR,newC});
              }
           }
         }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> vis(n,vector<int>(m,0));
      int count = 0;
        
      for(int i = 0; i < n; i++) {
         for(int j = 0; j < m; j++) {
             if(!vis[i][j] && grid[i][j] == '1') {
                count++;
                bfs(i,j,grid,vis);
             }
         }
      }        
      return count;      
    }
};
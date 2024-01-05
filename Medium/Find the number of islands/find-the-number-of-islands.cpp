//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
             
           for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
              int newR = r + i;
              int newC = c + j;
              if(newR >= 0 && newR < n && newC >= 0 && newC < m
                && !vis[newR][newC] && grid[newR][newC] == '1') {
                 vis[newR][newC] = 1;
                 q.push({newR,newC});
              }
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
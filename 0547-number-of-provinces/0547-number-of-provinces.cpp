class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for(int n : adj[node]) {
           if(!vis[n]) dfs(n, vis, adj);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> adj[n+1];
        vector<int> vis(n+1, 0);
        
        for(int i = 0; i < n; i++) {
           for(int j = 0; j < n; j++) {
              if(isConnected[i][j] == 1) {
                 adj[i+1].push_back(j+1);
                 adj[j+1].push_back(i+1);
              }
           }
        }
        
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
              count++;
              dfs(i, vis, adj);
            }
        }
         
        return count;  
    }
};
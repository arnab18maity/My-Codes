//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for(int n : adj[node]) {
           if(!vis[n]) dfs(n, vis, adj);
        }
    }
    
    int numProvinces(vector<vector<int>> isConnected, int V) {
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
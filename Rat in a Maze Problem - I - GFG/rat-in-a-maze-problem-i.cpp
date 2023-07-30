//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(int x,int y,int n,vector<vector<bool>> &visited,vector<vector<int>> &arr)
    {
        if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (arr[x][y] == 1)){
            return true;
        }
        
        return false;
    }
    
    void solve(int x,int y,vector<string> &ans,vector<vector<int>> &arr,int n,vector<vector<bool>> &visited, string path)
    {
        
        if(x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        // Down
        if(isSafe(x+1,y,n,visited,arr))
        {
            visited[x][y] = 1;
            solve(x+1,y,ans,arr,n,visited,path + 'D');
            visited[x][y] = 0;
        }
        
        // Left
        if(isSafe(x,y-1,n,visited,arr))
        {
            visited[x][y] = 1;
            solve(x,y-1,ans,arr,n,visited,path + 'L');
            visited[x][y] = 0;
        }
        
        // Right
        if(isSafe(x,y+1,n,visited,arr))
        {
            visited[x][y] = 1;
            solve(x,y+1,ans,arr,n,visited,path + 'R');
            visited[x][y] = 0;
        }
        
        // Up
         if(isSafe(x-1,y,n,visited,arr))
        {
            visited[x][y] = 1;
            solve(x-1,y,ans,arr,n,visited,path + 'U');
            visited[x][y] = 0;
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &arr, int n) {
        vector <string> ans;
        string path = "";
        if(arr[0][0] == 0) {
          return ans;
        }
        vector<vector<bool>> visited(n,vector<bool>(n,0));
        solve(0,0,ans,arr,n,visited,path);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
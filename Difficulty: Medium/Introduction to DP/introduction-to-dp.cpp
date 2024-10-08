//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    static const long long MOD = (int) 1e9 + 7;
    
    long long int helper(int n, vector<long long int> &dp) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        
        if(dp[n] != -1) return dp[n];
         
        return dp[n] = (helper(n-1, dp) + helper(n-2, dp)) % MOD;
    }
    
    long long int topDown(int n) {
        vector<long long int> dp(n+1,-1);
        return helper(n, dp);
    }
    
    long long int bottomUp(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
       
        long long int ans = 0, curr = 1, prev = 1;
        
        for(int i = 3; i <= n; i++) {
           ans = (curr + prev) % MOD;
           prev = curr;
           curr = ans;
        }
        
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
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int helper(vector<int>& stalls, int dist) {
        int prev = stalls[0], count = 1;
        
        for(int i = 1; i < stalls.size(); i++) {
           if(abs(stalls[i] - prev) >= dist) {
               count++;
               prev = stalls[i];
           }
        }
        
        return count;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = *max_element(stalls.begin(), stalls.end())
                   - *min_element(stalls.begin(), stalls.end());
        int ans = 0;
        
        while(low <= high) {
           int mid = low + (high - low)/2;
           
           if(helper(stalls,mid) >= k) {
              ans = mid;
              low = mid + 1;
           }
           else{
              high = mid - 1; 
           }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
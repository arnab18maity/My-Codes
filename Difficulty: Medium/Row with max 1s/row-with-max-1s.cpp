//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countOne(vector<int>&nums) {
        int first = lower_bound(nums.begin(),nums.end(),1) - nums.begin();
        int last = upper_bound(nums.begin(),nums.end(),1) - nums.begin();
        
        return last - first;
    }
  
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxi = 0, row = -1;
        
        for(int i = 0; i < n; i++) {
           int result = countOne(arr[i]);
           if(result > maxi) {
              maxi = result;
              row = i;
           }
        }
        
        return row;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
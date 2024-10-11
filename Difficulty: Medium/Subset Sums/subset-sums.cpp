//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void helper(int ind, int sum, vector<int> &arr, vector<int> &ans) {
        if(ind >= arr.size()){
           ans.push_back(sum);
           return;
        }
        
        helper(ind + 1, sum + arr[ind], arr, ans);
        helper(ind + 1, sum, arr, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        int sum = 0;
        int index = 0;
        helper(index, sum, arr, ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
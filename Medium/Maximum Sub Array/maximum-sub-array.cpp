//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    int finalStart = -1, finalEnd = -1, tempStart = -1, tempEnd = -1;
	    
	    long long maxSum = LONG_MIN;
	    long long sum = 0;
	    bool flag = false;
	    
	    for(int i = 0; i < n; i++) {
	       if(a[i] < 0) {
	         flag = true;
	         sum = 0;
	         tempStart = -1, tempEnd = -1;
	         continue;
	       }
	       
	       else if(a[i] >= 0 && tempStart == -1){
	          sum += a[i];
	          tempStart = i;
	          tempEnd = i;
	       }
	       else if(a[i] >= 0 && tempStart != -1) {
	           sum += a[i];
	           tempEnd = i;
	       }
	       
	       if(sum > maxSum) {
	            maxSum = sum;
	            finalStart = tempStart;
	            finalEnd = tempEnd;
	       }
           else if(sum == maxSum) {
                int currLen =  (tempEnd - tempStart) + 1;
                int prevLen = (finalEnd - finalStart) + 1;
                if(currLen > prevLen) {
                   finalStart = tempStart;
                   finalEnd = tempEnd; 
                }
            }
	       
	       
	    }
	    
	    if(!flag) {
	       vector<int> ans(a,a+n); 
	       return ans;
	    }
	    
	    if(finalStart == -1) return {-1};
	    
	    vector<int> ans;
	    
	    for(int i = finalStart; i <= finalEnd; i++) {
	        ans.push_back(a[i]);
	    }
	    
	    return ans;  
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> mp;
        int maxLen = 0;
        int sum = 0;
        
        for(int i = 0; i < N ; i++) {
           sum += A[i];
           
           if(sum == K) {
                 maxLen = i+1;
           }
           else {
                int rem = sum - K;
                if(mp.find(rem) != mp.end()) {
                    int len = i - mp[rem];
                    maxLen = max(len,maxLen);
                }
           }
           
           if(mp.find(sum) == mp.end()) {
                  mp[sum] = i;
           }
        }
        
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
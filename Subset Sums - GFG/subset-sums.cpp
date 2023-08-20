//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> solve(vector<int> &arr,int index,vector<int> &ans,int sum,int N)
    {
        if(index == -1){
            ans.push_back(sum);
            return ans;
        }
        
        sum += arr[index];
        solve(arr,index-1,ans,sum,N);
        
        sum -= arr[index];
        solve(arr,index-1,ans,sum,N);
        
        return ans;
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int> ans;
       solve(arr,N-1,ans,0,N);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
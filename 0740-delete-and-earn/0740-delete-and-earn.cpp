class Solution {
public:
 /*
    int solve(int index, int n, vector<int> &temp, unordered_map<int,int> &mp, vector<int> &dp) {
        if(index == n) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int notPick = solve(index+1,n,temp,mp,dp);
        int pick = temp[index]*mp[temp[index]];
        
        if(index + 1 < n && temp[index+1] == temp[index] + 1)  pick += solve(index+2,n,temp,mp,dp);
           
        else if(index + 1 < n && temp[index+1] != temp[index] + 1)  pick += solve(index+1,n,temp,mp,dp);
           
        
        return dp[index] = max(pick,notPick);
        
    }
    
*/
    
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i: nums) mp[i]++;
        
        vector<int> temp;
        for(auto i : mp) temp.push_back(i.first);
        sort(temp.begin(),temp.end());
        
        int n = temp.size();          
        vector<int> dp(n+1,0);
        
        int pick = 0, notPick = 0, prev1 = 0,prev2 = 0;
        
        for(int i = n-1; i >= 0; i--){
           notPick = prev1;
           pick = temp[i]*mp[temp[i]];
           if(i + 1 < n && temp[i+1] == temp[i] + 1)  pick += prev2;
           
           else if(i + 1 < n && temp[i+1] != temp[i] + 1)  pick += prev1;
            
           prev2 = prev1;
           prev1 = max(pick,notPick);
        }
        
        return prev1;
    }
};
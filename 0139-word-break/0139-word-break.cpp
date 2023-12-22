class Solution {
public:
/*
    bool function(int ind, int space, string &s, unordered_map<string,int> &mp, vector<vector<int>> &dp) {
        if(ind == 0) {
          string str = s.substr(0,space - 0);
          if(mp.find(str) !=  mp.end()) return true;
          return false;
        }
        
        if(dp[ind][space] != -1) return dp[ind][space];
        
        string str = s.substr(ind,space-ind);
        
        if(mp.find(str) !=  mp.end()) 
            return dp[ind][space] = function(ind-1,ind,s,mp,dp) || function(ind-1,space,s,mp,dp);
        
        return dp[ind][space] = function(ind-1,space,s,mp,dp);
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_map<string,int> mp;
       int n = s.size();
       for(auto it : wordDict) {
         mp[it]++;  
       }
      vector<vector<int>> dp(n,vector<int>(n+1,-1));  
      return function(n-1,n,s,mp,dp);
    }
*/
   bool wordBreak(string s, vector<string>& wordDict) {
       unordered_map<string,int> mp;
       int n = s.size();
       for(auto it : wordDict) {
         mp[it]++;  
       }
       
      // vector<vector<int>> dp(n,vector<int>(n+1,0)); 
      vector<int> prev(n+1,0), curr(n+1,0);
       
      // Base Case
      for(int space = 1; space <= n; space++) {
         string str = s.substr(0,space - 0);
          if(mp.find(str) !=  mp.end()) prev[space] = true;
          else prev[space] = false;
      }
       
      for(int ind = 1; ind < n; ind++) {
          for(int space = ind + 1; space <= n; space++) {
              string str = s.substr(ind,space-ind);
        
              if(mp.find(str) !=  mp.end()) 
                 prev[space] = prev[ind] || prev[space];

             else prev[space] = prev[space]; 
          }
          
          //prev = curr;
      }       
       
      return prev[n];
    } 
    
};
















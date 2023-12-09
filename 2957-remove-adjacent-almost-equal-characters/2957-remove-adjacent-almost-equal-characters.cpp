class Solution {
public:
  /*
    int f(int ind,string &word, vector<int> &dp) {
       if(ind <= 0) return 0;
        
       char next = word[ind-1] + 1;
       char prev = word[ind-1] - 1;
        
       if(dp[ind] != -1) return dp[ind];
        
       if(word[ind] != word[ind-1] && word[ind] != next && word[ind] != prev) {
           return dp[ind] = 0 + f(ind-1,word,dp);
       }
        
        return dp[ind] = 1 + f(ind-2,word,dp);
    }
 */   
    int removeAlmostEqualCharacters(string word) {
       int n = word.size();
       vector<int> dp(n+1,0);
        
       for(int ind = 2; ind <= n; ind++) {
           char next = word[ind-2] + 1;
           char prev = word[ind-2] - 1;

           if(word[ind-1] != word[ind-2] && word[ind-1] != next && word[ind-1] != prev) {
              dp[ind] = 0 + dp[ind-1];
           }
           else {
              dp[ind] =  1 + dp[ind-2];
           }
       }
        
       return dp[n]; 
    }
};
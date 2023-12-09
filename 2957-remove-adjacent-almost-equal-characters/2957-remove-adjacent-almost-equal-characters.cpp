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
       int curr = 0, prev1 = 0, prev2 = 0;
       for(int ind = 2; ind <= n; ind++) {
           char next = word[ind-2] + 1;
           char prev = word[ind-2] - 1;

           if(word[ind-1] != word[ind-2] && word[ind-1] != next && word[ind-1] != prev) {
              curr = 0 + prev1;
           }
           else {
              curr =  1 + prev2;
           }
           
           prev2 = prev1;
           prev1 = curr;
       }
        
       return prev1; 
    }
};
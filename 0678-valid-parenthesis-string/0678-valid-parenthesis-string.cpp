class Solution {
public:
    bool function(int ind, string &s, int count, vector<vector<int>> dp) {
        
        if(ind == s.size()) return count == 0;
        
        if(dp[ind][count] != -1) return dp[ind][count];
        
        bool left = false;
        bool right = false;
        bool star = false;
        
        if(s[ind] == '(') left = function(ind+1,s,count+1,dp);
        
        else if(s[ind] == ')' && count > 0) right = function(ind+1,s,count-1,dp); // If count go negative we cannot store it in the dp table. That's why we need to check whether the count is greater than 0 or not.
        
        else{
           star |= function(ind+1,s,count+1,dp);
           if(count > 0) star |= function(ind+1,s,count-1,dp); // Same reason for checking the count
           star |= function(ind+1,s,count,dp);
        }
        
        return dp[ind][count] = left || right || star;
    }
    
    bool checkValidString(string s) {
       if(s[0] == ')') return false;
        
//        int n = s.size();
//        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//        dp[n][0] = 1;
        
//        for(int ind = n-1; ind >= 0; ind--) {
//            for(int count = 0; count < n; count++) {
//                bool ans = false;

//                 if(s[ind] == '(') ans |= dp[ind+1][count+1];

//                 else if(s[ind] == ')' && count > 0) ans |= dp[ind+1][count-1];

//                 else{
//                    ans |=  dp[ind+1][count+1];
//                    if(count > 0) ans |=  dp[ind+1][count-1];
//                    ans |=  dp[ind+1][count];
//                 }

//                 dp[ind][count] = ans;
//            }
//        }
        
//        return dp[0][0]; 
        
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,0));
        dp[s.size()][0]=1;

        for(int ind=s.size()-1; ind>=0; ind--){
            for(int openingBracket=0; openingBracket<s.size(); openingBracket++){
                bool ans=false;
                if(s[ind]=='*'){
                    ans|=dp[ind+1][openingBracket+1];
                    if(openingBracket) ans|=dp[ind+1][openingBracket-1];
                    ans|=dp[ind+1][openingBracket];
                }else{
                    if(s[ind]=='('){
                        ans|=dp[ind+1][openingBracket+1];
                    }else{
                        if(openingBracket) ans|=dp[ind+1][openingBracket-1];
                    }
                }

                dp[ind][openingBracket]=ans;
            }
        }

        return dp[0][0];
    }
};
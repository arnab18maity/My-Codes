class Solution {
public:
    bool isPalindrome(string s) {
       string ans;
        
       for(int i = 0; i < s.size(); i++){
           if(isalnum(s[i])) 
               ans.push_back(tolower(s[i]));
       }
        
       for(int i = 0,j = ans.size()-1; i < j; i++,j--)
       {
           if(ans[i] != ans[j]) return false;
       }
        
        return true;
    }
};
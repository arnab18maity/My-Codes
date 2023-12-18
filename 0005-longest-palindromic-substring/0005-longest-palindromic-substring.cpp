class Solution {
public:
    void expand(int left, int right, string &s, string &ans) {
       while(left >= 0 && right < s.size()) {
          if(s[right] != s[left]) break;
          
          left--;
          right++;
       }
        
       if(right - left - 1 > ans.size()) {
          ans  = s.substr(left+1,right-left-1);
       }
    }
    
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {
           expand(i, i, s, ans); // For odd length palindrome
           expand(i, i+1, s, ans); // For Even Length Palindrome
        }

        return ans;
    }
};
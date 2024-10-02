class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int  i = 0;
        int count = 0;
        
       while(i < s.size()) {
          if(s[i] == '(') {
              count++;
              if(count != 1) res += s[i];
          }          
          else if(s[i] == ')') {
              count--;
              if(count != 0) res += s[i];
          }
          
          i++;
       }
        
       return res;
    }
};
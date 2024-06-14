class Solution {
public:
    void helper(int ind, bool start, double &result, string &s) {
       if(ind == s.size()) return;
       if(!start && s[ind] != ' ' && s[ind] != '+' && s[ind] != '-' && !(s[ind] >= '0' && s[ind] <= '9')) return;
       if(start && !(s[ind] >= '0' && s[ind] <= '9')) return;
       
        
       if(!start && s[ind] == ' ') {
           helper(ind+1,start,result,s);
           return;
       } 
        
       if(!start && s[ind] == '+') {
          helper(ind+1,true,result,s);
          return;
       }
    
       if(!start && s[ind] == '-') {
          helper(ind+1,true,result,s);
          result *= -1;
          return;
       }
      
       int digit = s[ind] - '0';
       result = (result*10 + digit);
       helper(ind+1,true,result,s);
    }
    
    int myAtoi(string s) {
        
      double result = 0;
      helper(0,false,result,s);
      
      result = result > INT_MAX ? INT_MAX : result;
      result = result < INT_MIN ? INT_MIN : result;
        
      return (int) result;
    }
};
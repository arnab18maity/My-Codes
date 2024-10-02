class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<int> list;
        string res = "";
        int  i = 0;
        int count = 0;
        
       while(i < s.size()) {
          if(s[i] == '(') {
              count++;
              if(count == 1) list.push_back(i);
          }          
          else if(s[i] == ')') {
              count--;
              if(count == 0) list.push_back(i);
          }
          
          i++;
       }
        
        int j = 0;
        
       for(int i = 0; i < s.size(); i++) {
          if(i == list[j]) {
             j++;
             continue;
          } 
           
          res += s[i];
       }
        
       return res;
    }
};
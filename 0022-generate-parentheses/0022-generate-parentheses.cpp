class Solution {
public:
    void f(int open, int close, vector<string> &ans, string cur) {
       if(open == 0 && close == 0) {
          ans.push_back(cur);
          return;
       }
        
       /*
          Whenever we have count of open brackets equal to the count of close brackets, we have only one           choice - that is to use '('. Because, all the brackets till now have been balanced. And we can           not start a new sequence with ')'.
          Whenever, count of close bracket is 0, we can only use '('.
       */
       if(open == close || close == 0) {
          cur.push_back('(');
          f(open-1,close,ans,cur);
       } 
        
       //  Whenever, count of open bracket is 0, we can only use ')'.
       else if(open == 0) {
          cur.push_back(')');
          f(open,close-1,ans,cur);
       }
        
       //  For all the remaining cases, we have both the choices.
       else{
          string temp1 = cur + '(';
          string temp2 = cur + ')';
           
          f(open-1,close,ans,temp1);
          f(open,close-1,ans,temp2);
       }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";

        f(n,n,ans,cur);
        return ans;
    }
};
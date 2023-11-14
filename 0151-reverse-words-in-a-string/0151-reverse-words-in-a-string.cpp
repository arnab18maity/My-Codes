class Solution {
public:
    string reverseWords(string s) {
       int i = s.size() - 1;
       stack<char> st;
       string ans;
       while(i >= 0) {
         while(i >= 0 && s[i] == ' ') {
            i--;
         }
         while(i >= 0 && s[i] != ' ') {
            st.push(s[i]);
            i--;
         }
         while(!st.empty()) {
            ans += st.top();
            st.pop();
         }
            ans += ' ';
       }        
      while(ans.back() == ' ') {
         ans.pop_back();
      }
      return ans;
    }
};
class Solution {
public:
    void function(int ind, int space, string &s, unordered_set<string>& st, vector<string>& ans) {
        if(ind == 0) {
          string str = s.substr(0,space - 0);
          if(st.find(str) !=  st.end()) ans.push_back(s);
          return;
        }
        
        string str = s.substr(ind,space-ind);
        
        if(st.find(str) !=  st.end()) {
           s.insert(s.begin() + ind, ' ');
           function(ind-1,ind,s,st,ans);
            
           s.erase(s.begin() + ind);
           function(ind-1,space,s,st,ans);
        }
        else {
           function(ind-1,space,s,st,ans);  
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        function(n-1,n,s,st,ans);
        return ans;
    }
};
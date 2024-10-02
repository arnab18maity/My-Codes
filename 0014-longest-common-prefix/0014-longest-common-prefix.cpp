class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = strs[0];
        
        for(int i = 1; i < n; i++) {
           string str = strs[i];
           int j = 0;
            
           for(j = 0; j < str.size(); j++) {
              if(str[j] != prefix[j]) break;
           }
            
           if(j == 0) return "";
           prefix = str.substr(0,j);
        }
        
        return prefix;
    }
};
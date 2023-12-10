class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char,int>mp;
        int maxLen = 0, i = 0, j = 0;
        
        while(j < s.size()) {
          mp[s[j]]++;
          
          if(mp.size() == j-i+1) {
             maxLen = max(maxLen,j-i+1);
          }
          else{
             while(mp.size() != j-i+1) {
                 mp[s[i]]--;
                 if(mp[s[i]] == 0) mp.erase(s[i]);
                 i++;
             }
            maxLen = max(maxLen,j-i+1); 
          }  
          j++;          
        }
        
        return maxLen;
    }
};
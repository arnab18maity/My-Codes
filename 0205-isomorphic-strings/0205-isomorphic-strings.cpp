class Solution {
public:
    bool isIsomorphic(string s, string t) {        
        unordered_map<char,char> mp;
        unordered_map<char,int> vis;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
          if(mp.find(s[i]) != mp.end()) {
              if(mp[s[i]] != t[i]) return false;
          }
          else{
             if(vis[t[i]] == 1) return false;
              
             vis[t[i]] = 1;
             mp[s[i]] = t[i];
          }
        }
        
        return true;
    }
};
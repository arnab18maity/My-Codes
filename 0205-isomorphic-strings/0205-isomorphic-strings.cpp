class Solution {
public:
    bool isIsomorphic(string s, string t) {        
       if(s.length() != t.length()) return false;
        
       unordered_map<char,char> mp1;
       unordered_map<char,bool> mp2;
        
       for(int i = 0; i < s.size(); i++) {
           
          if(mp2.find(t[i]) == mp2.end()) {
              if(mp1.find(s[i]) != mp1.end()) return false;
              
              mp1[s[i]] = t[i];
              mp2[t[i]] = true;
          }
           
          if(mp2.find(t[i]) != mp2.end()) {
             if(t[i] != mp1[s[i]]) return false;
          }
       }
        
       return true;
    }
};
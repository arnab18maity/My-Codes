class Solution {
public:
    int appendCharacters(string s, string t) {
        int l = 0, r = 0;
        
        while(l < s.size() && r < t.size()) {
           if(s[l] == t[r]) {
              l++;
              r++;
           }
           else l++;
        }
        
        if(r == t.size()) return 0;
        
        return t.size() - r;
    }
};
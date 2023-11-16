class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0;
        int count = 0;
        unordered_map<char,int> mp;
        //string ans = "";
        int length = INT_MAX;
        int start = 0;
        
        for(int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }
        
        count = mp.size();
        
        while(j < s.size()) {
           if(mp.find(s[j]) != mp.end()) mp[s[j]]--;
           if(mp.find(s[j]) != mp.end() && mp[s[j]] == 0) count--;
            
           if(count > 0) {
              j++;
           }
           else if(count == 0) {
             while(count == 0) { 
               if(length > j-i+1) {
                   start = i;
                   length = j-i+1;
               }
               if(mp.find(s[i]) == mp.end()) i++;
               else{
                 mp[s[i]]++;
                 if(mp[s[i]] == 1) count++;
                 i++;
               }               
             }               
            j++;
           } // End of else if
        }
        
        return length == INT_MAX ? "" : s.substr(start,length);
    }
};
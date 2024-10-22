class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       int n = s.size();
       vector<string> ans;
       unordered_map<string,int> mp;
        
       int l = 0, r = 9;
       
       while(r < n) {
          string temp = s.substr(l, 10);
          mp[temp]++;
          if(mp[temp] == 2) ans.push_back(temp);
          l++;
          r++;
       }
        
        
       return ans;
    }
};
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
          l++;
          r++;
       }
        
       for(auto it : mp) {
          if(it.second > 1) ans.push_back(it.first);
       }
        
       return ans;
    }
};
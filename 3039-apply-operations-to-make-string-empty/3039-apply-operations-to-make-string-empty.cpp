class Solution {
public:
    static bool sortbyval(const pair<char,int> &a, const pair<char,int> &b) {
           return (a.second < b.second);
    }
    
    string lastNonEmptyString(string s) {
       map<char,int> occurence;
       map<char,int> lastOccurence;
       int maxOccurance = 0;
        
       for(int i = 0; i < s.size(); i++) {
          occurence[s[i]]++;
          maxOccurance = max(occurence[s[i]],maxOccurance);
          lastOccurence[s[i]] = i;
       }
        
       for(auto it : occurence) {
          if(it.second != maxOccurance) lastOccurence.erase(it.first); 
       }
        
       vector<pair<char, int>> vec(lastOccurence.begin(), lastOccurence.end());
       sort(vec.begin(), vec.end(), sortbyval);
        
       string ans = "";
       for(auto it : vec) {
         ans += it.first;
       }
        
       return ans;  
       
    }
};
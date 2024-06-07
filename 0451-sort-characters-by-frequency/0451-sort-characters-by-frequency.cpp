class Solution {
public:
    static bool comp(pair<char,int> p1, pair<char,int>p2) {
        return p1.second > p2.second;
    }
    
    string frequencySort(string s) {
        int n = s.size();
        pair<char,int> p;
        p.first = '0';
        p.second = 0;
        
        vector<pair<char,int>> freq(256,p);
        
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            int index = s[i] - '0';
            freq[index].first = ch;
            freq[index].second++;
        }
        
        sort(freq.begin(),freq.end(), comp);        
        string ans = "";
        
        for(int i = 0; i < 256; i++) {
           if(freq[i].second == 0) break;
           int t = freq[i].second;
           while(t--) {
              ans += freq[i].first;
           }
        }
        
        return ans;
    }
};
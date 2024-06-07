struct Compare {
       bool operator()(pair<string,int> &a, pair<string,int> &b) {
         if (a.second == b.second) {
            return a.first > b.first;
         }
           
         return a.second < b.second;
       }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
       priority_queue < pair<string,int>, vector<pair<string,int>>, Compare > pq;
       unordered_map<string,int> mp;
       vector<string> ans;
       
        for(auto i : words) {
           mp[i]++;
        }
        
        for(auto it : mp) {
          pq.push(make_pair(it.first,it.second));
        }
        
        while(k--) {
          ans.push_back(pq.top().first);
          pq.pop();
        }
        
        return ans;
    }
};
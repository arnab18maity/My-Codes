struct Compare {
       bool operator()(pair<int,int> &a, pair<int,int> &b) {
         if (a.second == b.second) {
            return a.first > b.first;
         }
           
         return a.second < b.second;
       }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       priority_queue < pair<int,int>, vector<pair<int,int>>, Compare > pq;
       unordered_map<int,int> mp;
       vector<int> ans;
       
        for(auto i : nums) {
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
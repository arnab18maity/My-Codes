class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
      int n  = score.size();
      vector<string> ans(n,"");
      priority_queue<pair<int,int>> pq;
        
      for(int i = 0; i < n; i++) {
         pq.push({score[i],i});
      }
        
      for(int i = 1; i <= n; i++) {
         if(i == 1) {
           pair p = pq.top();
           pq.pop();
           int ind = p.second;
           ans[ind] = "Gold Medal";
         }
         else if(i == 2) {
           pair p = pq.top();
           pq.pop();
           int ind = p.second;
           ans[ind] = "Silver Medal"; 
         }
         else if(i == 3) {
           pair p = pq.top();
           pq.pop();
           int ind = p.second;
           ans[ind] = "Bronze Medal";
         }
         else{
           pair p = pq.top();
           pq.pop();
           int ind = p.second;
           ans[ind] = to_string(i);  
         }
      }
        
      return ans;
    }
};
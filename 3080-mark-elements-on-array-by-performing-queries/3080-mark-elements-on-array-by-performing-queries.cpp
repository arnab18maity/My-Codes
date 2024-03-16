class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i = 0; i < nums.size(); i++) {
           pq.push({nums[i],i});
        }
        
        
        int m = queries.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        vector<long long> result;
        vector<int>marked(nums.size(),0);
        
        for(int i = 0; i < m; i++) {
            int index = queries[i][0];
            int k = queries[i][1];
            
            // Mark the index
            if(!marked[index]){
               marked[index] = 1;
               sum -= nums[index];
            }
            
            // mark k unmarked elements in the array with the smallest values
            while(k > 0 && !pq.empty()) {
               pair<int,int> x = pq.top();
               pq.pop();
               int ind = x.second;
               int val = x.first;
               if(marked[ind] == 0) {
                  marked[ind] = 1;
                  sum -= nums[ind];
                  k--;
               }
            }
            
            result.push_back(sum);
        }
        
        return result;
    }
};
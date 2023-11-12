class Solution {
public:    
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long ans = 0;
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        
        while(j < nums.size()) {
           sum += nums[j];
           mp[nums[j]]++;
            
           if(j - i + 1 < k) {         
               j++;
           }
            
           else if(j - i + 1 == k){
             if(mp.size() == k) {
                ans = max(ans,sum);
             }
             sum -= nums[i];
             mp[nums[i]]--;
             if(mp[nums[i]] == 0) mp.erase(nums[i]);
             i++;
             j++;
           }
        }
        
       return ans;
    }
};
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxLength = INT_MIN;
        int i = 0, j = 0;
        unordered_map<int,int> mp;
        
        while(j < nums.size()) {
           mp[nums[j]]++;
            
           if(mp[nums[j]] > k) {
              while(mp[nums[j]] > k) {
                 mp[nums[i]]--;
                 i++;
              }
           }
            
           maxLength = max(maxLength,j-i+1);
           j++;
        }
        
       return maxLength;
    }
};
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
      int n = nums.size();
      long long ans = -1;
      sort(nums.begin(),nums.end());
      vector<long long> prefix(n,0);
        
      long long sum = 0;
      for(int i = 0; i < n; i++) {
         prefix[i] = sum;
         sum += nums[i];
      }
        
      for(auto it : prefix) {
         cout << it << " ";
      }
        
      for(int i = 0; i < n; i++) {
         if(nums[i] < prefix[i]) {
           ans = max(ans,prefix[i] + (long long)nums[i]);
         }
      }
        
        return ans;
    }
};
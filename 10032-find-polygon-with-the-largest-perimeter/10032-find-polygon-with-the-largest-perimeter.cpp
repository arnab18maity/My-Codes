class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
      int n = nums.size();
      long long ans = -1;
      sort(nums.begin(),nums.end());
        
      long long sum = 0;
      for(int i = 0; i < n; i++) {
         sum += nums[i];
      }
        
     // Loop through the sorted vector from the end to find the largest perimeter
      for(int i = n-1; i >= 2; i--) {
         sum -= nums[i]; // Remove the largest element from sum
         if(sum  > nums[i]) {
           return sum + nums[i];
         }
      }
        
        return ans;
    }
};
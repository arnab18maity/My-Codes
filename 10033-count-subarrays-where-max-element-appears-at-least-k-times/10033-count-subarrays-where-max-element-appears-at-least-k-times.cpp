class Solution {
public:
    long long atMostKminus1(vector<int> &nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int i = 0, j = 0, maxcnt = 0;
        long long count = 0;
        
        while(j < nums.size()) {
          if(nums[j] == maxi) maxcnt++;
      
          if(maxcnt > k) {
            while(maxcnt > k) {
              if(nums[i] == maxi) maxcnt--;
              i++;
            }
          }
           
          count += j - i + 1;
          j++;
        }
        
        return count;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long totalSubArray = (long long) n*(n+1)/2;
      
        return totalSubArray - atMostKminus1(nums,k-1);
    }
};
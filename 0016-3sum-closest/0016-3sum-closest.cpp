class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = INT_MAX;
        int minDiff = INT_MAX;
        
        for(int i = 0; i < n-2; i++) {
            int j = i+1;
            int k = n-1;
            
            while(j < k) {
               int sum = nums[i] + nums[j] + nums[k];
                
               if(abs(target - sum) < minDiff) {
                  closest = sum;
                  minDiff = abs(target - sum);
               }
                
               if(sum > target) k--;
               else if(sum < target) j++;
               else return sum;
            }
        }
        
        return closest;
    }
};
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // https://leetcode.com/problems/patching-array/discuss/78492/C%2B%2B-8ms-greedy-solution-with-explanation
        int i = 0, count = 0;
        int k = nums.size();
        long long maxAchieve = 0;
        
        while(maxAchieve < n) {
           if(i < k && nums[i] <= maxAchieve + 1) {
               maxAchieve += nums[i];
               i++;
           }
           else{
              maxAchieve += (maxAchieve + 1);
              count++;
           }
        }
        
        return count;
    }
};
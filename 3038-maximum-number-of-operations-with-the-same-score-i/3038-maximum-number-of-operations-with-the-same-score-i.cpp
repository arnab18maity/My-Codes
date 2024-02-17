class Solution {
public:
    int maxOperations(vector<int>& nums) {
       int maxOperation = 1;
       int sum = nums[0] + nums[1];
        
      for(int i = 2; i < nums.size() - 1; i+=2) {
         int s = nums[i] + nums[i+1];
         if(s == sum) maxOperation++;
         else break;
      }
        
      return maxOperation;
      
    }
};
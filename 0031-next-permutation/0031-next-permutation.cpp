class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int index = -1;
       for(int i = nums.size() - 2; i >= 0; i--) {
           if(nums[i] < nums[i+1]) {
               index = i;
               break;
           }
       }
        
       if(index == -1) {
         reverse(nums.begin(),nums.end());
         return;
       }
        
       int element = INT_MAX;
       int ind = -1;
       for(int i = nums.size() - 1; i > index; i--) {
          if(nums[i] > nums[index]) {
             element = nums[i];
             ind = i;
             break;
          } 
       }
        
       swap(nums[index],nums[ind]);
        
       reverse(nums.begin() + index + 1, nums.end());
    }
};
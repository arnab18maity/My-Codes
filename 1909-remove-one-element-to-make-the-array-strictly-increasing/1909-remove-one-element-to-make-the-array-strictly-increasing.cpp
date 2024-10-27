class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
       int count = 0, prev = nums[0];
        
       int i = 1;
        
       while(i < nums.size()) {
          if(nums[i] <= prev) {
             if(count == 1) return false;
              
             count++;          
             if(i == 1 || nums[i] > nums[i-2]) { // we remove the element from i - 1 position because it is bigger & it is causing problem. i th index is greater than i-2 th index so we can surely say i-1 is causing the problem.
                prev = nums[i];
             }
              
             // Otherwise we remove the current index because it is smaller & it is causing problem. In this case we need to do nothing because previous is already at its correct position.
               
          }
          else {
             prev = nums[i];
          }
           
           i++;
       }
        
        return true;
    }
};
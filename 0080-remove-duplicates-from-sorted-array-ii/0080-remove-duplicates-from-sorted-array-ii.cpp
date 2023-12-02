class Solution {
public:
    int removeDuplicates(vector<int>& nums) {        
        int count = 1;
        int element = nums[0];
        int i = 1;
        
        while(i < nums.size()) {
          if(nums[i] == element) {
              count++;
              if(count <= 2) i++;
          }
          else if(nums[i] != element) {
             count = 1;
             element = nums[i];
             i++;
          }
            
          if(count > 2) {
             nums.erase(nums.begin() + i);
             count--;
          }
          
        }
        
        return nums.size();
    }
};
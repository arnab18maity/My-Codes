class Solution {
public:
    int func(vector<int>& nums, int mid) {
       int count = 0;
       for(int i = 0; i < nums.size(); i++) {
           if(nums[i] <= mid) count++;
       }         
       return count;
    }
    
    int findDuplicate(vector<int>& nums) {
       // Binary Search on Answer        
       int low = 1;
       int high = nums.size() - 1;
       while(low <= high) {
          int mid = (low+high)/2;
          int cnt = func(nums,mid);
          
          if(cnt <= mid) {
             low = mid + 1;
          }
          else{
             high = mid - 1;
          }
       }
        
       return low;
    }
/*    
    int findDuplicate(vector<int>& nums) {
       int slow = nums[0];
       int fast = nums[nums[0]];
       
       while(slow != fast) {
          slow = nums[slow];
          fast = nums[nums[fast]];
       }
        
       fast = 0;
        
       while(slow != fast) {
         slow = nums[slow];
         fast = nums[fast];
       }
        
       return slow; // We can return fast also
    }
  */
};





































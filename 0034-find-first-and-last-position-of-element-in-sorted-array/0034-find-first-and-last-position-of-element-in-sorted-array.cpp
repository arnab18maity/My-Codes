class Solution {
public:
    int ub(vector<int> &nums, int target) {
       int low = 0, high = nums.size() - 1;
       int ans = nums.size();
      
       while(low <= high) {
          int mid = (low + high)/2;
           
          if(nums[mid] > target) {
             ans = mid;
             high = mid - 1;
          }
          else {
             low = mid + 1;
          }
       }
        
       return ans;
    }
    
    int lb(vector<int> &nums, int target) {
       int low = 0, high = nums.size() - 1;
       int ans = nums.size();
      
       while(low <= high) {
          int mid = (low + high)/2;
           
          if(nums[mid] == target) {
             ans = mid;
             high = mid - 1;
          }
          else if(nums[mid] < target) {
             low = mid + 1;
          }
          else{
             high = mid - 1;
          }
       }
        
       return ans; 
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
       int fo = lb(nums,target);
       if(fo == nums.size()) return {-1,-1};
       int lo = ub(nums,target);
        
       return {fo,lo-1};
    }
};
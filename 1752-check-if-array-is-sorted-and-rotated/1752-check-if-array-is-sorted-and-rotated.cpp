class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), count = 0;
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1]){
               count = i; 
            } 
        }
        
        bool flag = true;
        
        for(int i = 0; i < n; i++) {
            if(temp[i] != nums[(i+count)%n]) {
              flag = false;
              break;
            }
        }
        
        return flag;
    }
};
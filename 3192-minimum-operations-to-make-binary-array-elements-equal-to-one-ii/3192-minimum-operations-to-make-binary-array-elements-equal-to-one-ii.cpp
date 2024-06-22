class Solution {
public:
    int minOperations(vector<int>& nums) {
       int count = 0;
        
       for(int i = 0; i < nums.size(); i++) {
           int num;
           if(count % 2 == 0) num = nums[i];
           else num = !nums[i];
           
           if(num == 0) count++;
       }
        
       return count;
    }
};
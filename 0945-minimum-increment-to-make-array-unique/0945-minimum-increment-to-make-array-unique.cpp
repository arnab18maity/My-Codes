class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> st;
        st.insert(nums[0]);
        int next = nums[0] + 1;
        int count = 0;
        
        for(int i = 1; i < nums.size(); i++) {
          if(nums[i] >= next) {
             st.insert(nums[i]);
             next = nums[i] + 1;
          }
          else if(st.find(nums[i]) != st.end()) {
             count += (next - nums[i]);
             st.insert(next);
             next = next + 1;      
          }
          
        }
        
        return count;
    }
};
    











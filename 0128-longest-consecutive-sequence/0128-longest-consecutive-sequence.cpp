class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int count = 0, longest = 0, prev = INT_MIN;
        
//         for(int i = 0; i < nums.size(); i++) {
//           if(nums[i] - 1 == prev) {
//              count++;
//              prev = nums[i];
//           } 
//           else if(nums[i] != prev) {
//              count = 1;
//              prev = nums[i];
//           }
            
//           longest = max(longest,count);
//         }
        
        unordered_set<int> st(nums.begin(),nums.end());
        int longest = 0;
        
        for(auto it : st) {
          if(st.find(it-1) == st.end()) {
             int start = it;
             int count = 1;
             int x = start + 1;
             while(st.find(x) != st.end()) {
                count++;
                x = x + 1;
             }
            
             longest = max(count,longest);
          }
        }
        
       return longest;
    }
};
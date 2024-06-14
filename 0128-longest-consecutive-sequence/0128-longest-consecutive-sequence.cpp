class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st(nums.begin(),nums.end());
        int longest = 1;
        
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
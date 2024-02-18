class Solution {
public:
    int length(int num) {
      if(num == 0) return 1;
      int count = 0;
      while(num > 0) {
        num /= 10;
        count++;
      }
        
      return count;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
       int maxPrefix = 0;
       unordered_set<int> st;
        
       for(auto it : arr1) {
          while(it > 0) {
             st.insert(it);
             it /= 10;
          }
       }
        
       for(auto it : arr2) {
          while(it > 0) {
             if(st.find(it) != st.end()) {
               maxPrefix = max(maxPrefix, length(it));
               break;
             }
              
             it /= 10;
          } 
       }
        
       return maxPrefix;
    }
};
class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char,int> mp;
        
       for(auto it : s) {
         mp[it]++;
       }
        
       int count = 0;
       int hasOdd = 0;
        
       for(auto it : mp) {
         if(it.second % 2 == 0) count += it.second;
         else if(it.second % 2 != 0) {
            count += it.second-1;
            hasOdd = 1;
         }
       }
        
       return count + hasOdd;
    }
};

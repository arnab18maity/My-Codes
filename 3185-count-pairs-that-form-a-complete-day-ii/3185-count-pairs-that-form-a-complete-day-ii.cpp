class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
      long long count = 0;
      int n = hours.size();
      unordered_map<int,int> mp;
        
      for(int i = 0; i < n; i++) {
         int hrs = hours[i] % 24;
          
         int need;
         if(hrs == 0) need = 0;
         else need = 24 - hrs;
          
         count += mp[need];
         mp[hrs]++;
      }
        
      return count;
    }
};
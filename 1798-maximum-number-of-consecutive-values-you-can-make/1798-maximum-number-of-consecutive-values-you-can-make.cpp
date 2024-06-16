class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
     // Reference Problem : 330. Patching  Array
        
       sort(coins.begin(),coins.end());
       int maxAchieve = 0;
       int n = coins.size(), i = 0;
        
       while(i < n) {
         if(coins[i] <= maxAchieve + 1) {
            maxAchieve += coins[i];
            i++;
         }
         else break;
       }
        
      return maxAchieve + 1;
    }
};
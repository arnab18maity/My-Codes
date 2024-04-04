class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> ans(n+1,0);
        
       for(int i = 1; i <= n; i++) {
          int num = i;
          int set = 0;
          while(num > 0) {
            if(num % 2) set++;
            num /= 2;
          }
           
          ans[i] = set;
       }
        
      return ans;
    }
};
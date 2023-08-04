class Solution {
public:

    int climbStairs(int n) {       
      if(n == 0){
            return 1;
        }
        
       int curr = 1;
       int prv  = 1;
       int ans  = 1;
       for(int i = 2; i <= n ; i++){
           ans = prv + curr;
           prv = curr;
           curr = ans;
       }
        
      return ans;
    }
};

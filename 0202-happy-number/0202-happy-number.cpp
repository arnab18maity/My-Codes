class Solution {
public:
    long long squareSum(int v) {
       long long res = 0;
       while(v != 0) {
         int d = v%10;
         res += pow(d,2);
         v = v/10;
       }        
      return res;
    }
    
    bool isHappy(int n) {
     /*
        Floyd's Cycle Detection Algorithm.
        If there is a cycle fast & slow will become equal at some point.
        If there is no cycle fast pointer will give the result 1
     */
        int slow = n;
        int fast = squareSum(n);
        while(fast != 1 && fast != slow){
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }
        return fast == 1;
    }
/*    
    bool isHappy(int n) {
      int temp = n;
      unordered_map<long long,bool> mp;
      mp[temp] = true;
        
      while(1) {
        long long val = squareSum(temp);
        if(val == 1) return true;
        if(mp.find(val) != mp.end()) return false;
        mp[val] = true;
        temp = val;
      }
        
      return false;
    }
*/
};
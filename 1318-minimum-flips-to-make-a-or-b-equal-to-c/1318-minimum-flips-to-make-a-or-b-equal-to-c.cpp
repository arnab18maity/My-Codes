class Solution {
public:
    int minFlips(int a, int b, int c) {
       int count = 0;
        
       for(int i = 0; i <= 31; i++) {
          int a1 = (a & (1 << i)) > 0 ? 1 : 0;
          int b1 = (b & (1 << i)) > 0 ? 1 : 0;
          int c1 = (c & (1 << i)) > 0 ? 1 : 0;

          if((a1 | b1) == c1) continue;
          else if((a1 == 1 && b1 == 1) && c1 == 0) count += 2;
          else count++;
          
       }
        
       return count;
    }
};
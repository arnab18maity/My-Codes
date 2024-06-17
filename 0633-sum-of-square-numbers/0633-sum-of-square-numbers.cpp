class Solution {
public:
    bool judgeSquareSum(int c) {
      if(c == 0) return true;
      
      double given = (double) c;
      double num = 0;  
      double a = 0;  
        
      while(num <= c) {
        a++;
        num = a * a;    
        double rem = given - num;
        double b = ceil(sqrt(rem));
        double res = num + (b*b);
        if(res == given) return true;
      }
        
       return false;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long num = abs(n);
        
     /*   
        for(long i = 1; i <= num; i++) {
           res = res * x;
        }
    */   
        
        while (num) {
            if(num % 2 == 1) {
               res = res * x;
               num = num - 1;
            }
            else{
               x = x * x;
               num = num/2;
            }
        }
   
        if(n < 0) res = (double)(1.0)/(double)(res);
        
        return res;
    }
};
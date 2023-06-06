class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) {
            return 0;
        }
        
        if(divisor == 1) {
            return dividend;
        }

        if(dividend == INT_MAX && (divisor == 1 || divisor == -1)) {
            if(divisor == 1) {
                return INT_MAX;
            }

            return INT_MAX * -1;
        }

        if(dividend == INT_MIN && (divisor == 1 || divisor == -1)) {
            if(divisor == 1) {
              return INT_MIN;
            }

            return INT_MAX;
        }
        

        long long temp_dd = dividend;
        long long temp_dr = divisor;

        if(dividend < 0) {
          temp_dd *= -1;
        }
        
        if(divisor < 0) {
          temp_dr *= -1;
        }

        long long res = 0 , i = 1;
        
        for(i = 1 ; res <= temp_dd ; i++) {
            res += temp_dr;
            if(res > temp_dd) {
                break;
            }
        }

        i = i - 1;

        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            return -1*i;
        }

        return i;
    }
};
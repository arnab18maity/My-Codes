class Solution {
public:
    int totalMoney(int n) {
       if(n <= 7) return (n*(n+1))/2; 
       
       int wk = n/7;
       int temp = wk;
       int day = n%7;
       int initial = 28;
       int totMoney = 0;
        
       while(wk > 0) {
         totMoney += initial;
         initial += 7;
         wk--;
       }
       
       int dmoney = temp + 1;
        
       while(day > 0) {
          totMoney += dmoney;
          dmoney++;
          day--;
       }
        
       return totMoney;
    }
};
class Solution {
private:
    int func(int x,int y, vector<int>& dp) {
       if(x == y) return 0;
       if(y > x) return y-x;
        
       if(dp[x] != -1) return dp[x];
       
       int div11 = INT_MAX;
       int div5 = INT_MAX;
        
       if(x % 11 == 0) div11 =  1 + func(x/11, y,dp);
       else {
           // To get the previous multiple of 11 we have to decrement the number x % 11 times
           // Eg. For 59 we have to decrement the number 59 % 11 = 4 times, then it will be 55
           // Now we have to make the call for x/11 because it is the previous multiple of 11
           // Eg. For 59 we have to make call for 59/11 = 5 because 55/11 = 5
           // +1 for the current operation of (x/11)
           int prevMultiple = x%11 + 1 + func(x/11, y,dp);
           
           // To get the next multiple of 11 we have to increment the number (11 - x%11) times
           // Eg. For 59 we have to increment the number (11 - 59 % 11) = 7 times, then it will be 66
           // Now we have to make the call for (x/11 + 1) because it is the next multiple of 11
           // Eg. For 59 we have to make call for 59/11 + 1 = 6 because 66/11 = 6
           // +1 for the current operation of (x/11 + 1)
           int nextMultiple = (11 - x%11) + 1 + func(x/11 + 1, y,dp);
           
           // We have to store the minimum of both
           div11 =  min(prevMultiple,nextMultiple);
       }
        
       if(x % 5 == 0) div5 =  1 + func(x/5, y,dp); 
       else {
           int prevMultiple = x%5 + 1 + func(x/5, y,dp);
           int nextMultiple = (5 - x%5) + 1 + func(x/5 + 1, y,dp);
           div5 =  min(prevMultiple,nextMultiple);
       }
        
       int dec1 = 1 + func(x-1, y,dp);
               
       return dp[x] = min({div11,div5,dec1});
    }
    
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x == y) return 0;
        if(y > x) return y-x;
        
        vector<int> dp(x+1, -1);
        return func(x,y,dp);
    }
};
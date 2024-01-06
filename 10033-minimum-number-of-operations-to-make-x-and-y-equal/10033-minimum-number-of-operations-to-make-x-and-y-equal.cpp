class Solution {
private:
    int func(int x,int y, vector<int>& dp) {
       if(x == y) return 0;
       if(y > x) return y-x;
        
       if(dp[x] != -1) return dp[x];
       
       int div11 = INT_MAX;
       int div5 = INT_MAX;
        
       if(x % 11 == 0) div11 =  1 + func(x/11, y,dp);
       else div11 = min(x%11 + 1 + func(x/11, y,dp), (11 - x%11) + 1 + func(x/11 + 1, y,dp));
        
       if(x % 5 == 0) div5 =  1 + func(x/5, y,dp); 
       else div5 =  min(x%5 + 1 + func(x/5, y,dp), (5-x%5) + 1 + func(x/5 + 1, y,dp));
        
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
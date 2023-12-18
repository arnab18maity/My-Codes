class Solution {
public:
/*
    int solve(int ind, int expireDay, vector<int>&days, vector<int>&cost, vector<vector<int>> &dp)
    {
        if(ind == 0) {
          if(days[0] >= expireDay) return 0;
          
          return min(cost[0],min(cost[1],cost[2]));
        }
        
        if(dp[ind][expireDay] != -1) return dp[ind][expireDay];
        
        if(days[ind] >= expireDay) {
            return dp[ind][expireDay] = 0 + solve(ind-1,expireDay,days,cost, dp);
        }
        
        int oneDay = cost[0] + solve(ind-1, days[ind], days, cost, dp); 
        
        int d = max(0,days[ind] - 6);
        int sevenDay = cost[1] + solve(ind-1, d, days, cost, dp);
        
        d = max(0, days[ind] - 29);
        int thirtyDay = cost[2] + solve(ind-1, d, days, cost, dp);
            
        return dp[ind][expireDay] = min(oneDay,min(sevenDay,thirtyDay));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& cost) {
       int n = days.size();
       vector<vector<int>> dp(n,vector<int>(367,-1));
       return solve(n-1, 366, days, cost, dp); 
    }
    
*/
    
    int mincostTickets(vector<int>& days, vector<int>& cost) {
       int n = days.size();
       //vector<vector<int>> dp(n,vector<int>(367,0));
       vector<int> prev(367,0), curr(367,0);
        
       for(int j = 0; j <= 366; j++) {
          if(days[0] < j) {
             prev[j] = min(cost[0],min(cost[1],cost[2]));
          }
       }
        
       for(int ind = 1; ind < n; ind++) {
          for(int expireDay = 0; expireDay <= 366; expireDay++) {
              
            if(days[ind] >= expireDay) {
                curr[expireDay] = 0 + prev[expireDay];
            }
            else {
                int oneDay = cost[0] + prev[days[ind]]; 

                int d = max(0,days[ind] - 6);
                int sevenDay = cost[1] + prev[d];

                d = max(0, days[ind] - 29);
                int thirtyDay = cost[2] + prev[d];

                curr[expireDay] = min(oneDay,min(sevenDay,thirtyDay));
            }
              
          }
           
           prev = curr;
       }
        
        return prev[366];
    }

};

































































class Solution {
public:
//     long long helper(int ind, int prev, vector<int>& power, vector<vector<long long>> &dp) {
//        if(ind >= power.size()) return 0;
//        if(dp[ind][prev] != -1) return dp[ind][prev];
        
//        long long notTake = helper(ind+1,prev,power,dp); 
       
//        long long take = 0;
        
//        int currValue = power[ind];
//        int diff = currValue - prev;
            
//        if(currValue == prev || prev == 0 || diff >= 3) {
//          take = power[ind] + helper(ind+1,power[ind],power,dp);
//        }
        

//        return dp[ind][prev] = max(take,notTake);
//     }
    
    
//     long long maximumTotalDamage(vector<int>& power) {
//          sort(power.begin(),power.end());
//          int n = power.size();
//          int maxi = power[n-1];
        
//          // vector<vector<long long>> dp(n, vector<long long>(maxi+1, -1));
//         // return helper(0,0,power,dp); 
        
//         //vector<vector<long long>> dp(n+1, vector<long long>(maxi+1, 0));
        
//         vector<long long> before(maxi+1, 0), curr(maxi+1, 0);
        
//         for(int ind = n-1; ind >= 0; ind--) {
//            for(int prev = 0; prev <= maxi; prev++) {
//                long long notTake = before[prev]; 
       
//                long long take = 0;

//                int currValue = power[ind];
//                int diff = currValue - prev;

//                if(currValue == prev || prev == 0 || diff >= 3) {
//                  take = power[ind] + before[power[ind]];
//                }

//                curr[prev] = max(take,notTake); 
//            }
            
//            before = curr;
//         }
        
//         return before[0];
//     }

    
    
    
//  The above solution is giving TLE. So below is the optimized approach.
//  Some Key Points :
//  Sort the array & extract the unique digits. Also reserve their frequency.
//  If we ever decide to use some spell with power x, then we will use all spells with power x.
//  When we are at index i, we can figure out the next index where we should jump. 
//  The difference of the values between the two indices should be >= 3.
//  Based on the above observation, we will write our algorithm.
    
    long long helper(int ind,  vector<int> &unique, vector<int> &nextIndex, unordered_map<int,int> &mp, vector<long long> &dp) {
        if(ind >= unique.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        long long notTake = helper(ind+1, unique, nextIndex, mp, dp);
        
        long long take = (1ll*unique[ind]*(mp[unique[ind]]) + 1ll*helper(nextIndex[ind], unique, nextIndex, mp, dp));
        
        return dp[ind] = max(take, notTake);
    }
    
    long long maximumTotalDamage(vector<int>& power) {
       unordered_map<int,int> mp;
    
       for(auto it : power) {
          mp[it]++;
       }
       
       vector<int> unique;
        
       for(auto it : mp) {
          unique.push_back(it.first);
       }
        
       sort(unique.begin(), unique.end());
       int n = unique.size();
        
       vector<int> nextIndex(n,-1);
        
       for(int i = 0; i < n; i++) {
         nextIndex[i] = lower_bound(unique.begin(), unique.end(), unique[i] + 3) -
                        unique.begin();
       }
        
       // vector<long long> dp(n, -1);        
       // return helper(0, unique, nextIndex, mp, dp);
        
       vector<long long> dp(n+1, 0);
        
       for(int ind = n-1; ind >= 0; ind--) {
          long long notTake = dp[ind+1];   
          long long take = (1ll*unique[ind]*(mp[unique[ind]]) + 1ll*dp[nextIndex[ind]]);
          dp[ind] = max(take, notTake); 
       }
        
       return dp[0];
    }
};













































































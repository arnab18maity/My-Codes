class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {        
        long long n = health.size();
        vector<long long> time;
        vector<pair<long double,int>> arr; // (damage per second, index);
        
        for(int i = 0; i < n; i++){
            time.push_back(1LL*ceil((1.0*health[i])/(1.0*power)));
            long double dps = 1LL*(1.0*damage[i])/(1.0*time[i]);
            arr.push_back({dps,i});
        }
        
        sort(arr.rbegin(),arr.rend());
        
        long long ans = 0;
        
        long long totalDamage = accumulate(damage.begin(),damage.end(),0LL);     
        
        for(int i = 0; i < n; i++){
            int ind = arr[i].second;  
            ans += totalDamage*(time[ind])*1LL;
            totalDamage -= damage[ind];
        }
        
        return ans; 
    }
};
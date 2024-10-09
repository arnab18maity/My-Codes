class Solution {
public:
    long long helper(vector<int>&piles, int rate) {
       long long total = 0;
       for(int i = 0; i < piles.size(); i++) {
           total += (piles[i] / rate);
           if(piles[i] % rate) total += 1;
       }
        
       return total;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
       long long low = 1;
       long long high = *max_element(piles.begin(),piles.end());
       long long ans = INT_MAX;
        
       while(low <= high) {
         long long mid = low + (high-low)/2;
         
         if(helper(piles,mid) <= h) {
            ans = mid;
            high = mid - 1;
         }
         else {
            low = mid + 1;
         }
       }
        
       return (int) ans;
    }
};
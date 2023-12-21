class Solution {
public:
    int reqDays(int capacity, vector<int>& weights) {
        int reqDays = 1;
        int currWeight = 0;
        
        for(int i = 0; i < weights.size(); i++) {
           if(currWeight + weights[i] <= capacity) {
               currWeight += weights[i];
           }
           else{
               reqDays++;
               currWeight = weights[i];
           }
        }
        
        return reqDays;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
       int low = *max_element(weights.begin(),weights.end());
       int high = accumulate(weights.begin(),weights.end(),0);
       int ans = 0;
        
       while(low <= high) {
         int mid = (low+high)/2;
         
         if(reqDays(mid,weights) <= days) {
            ans = mid;
            high = mid - 1;
         }
           
         else{
            low = mid + 1;
         }
       }
        
        return ans;
    }
};










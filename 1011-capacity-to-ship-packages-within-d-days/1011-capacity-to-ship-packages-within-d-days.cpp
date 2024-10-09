class Solution {
public:
    int helper(vector<int> &weights, int capacity) {
        int count = 0;
        int total = 0;
        
        for(int i = 0; i < weights.size(); i++) {
           total += weights[i];
            
           if(total > capacity) {
              count++;
              total = weights[i];
           } 
        }
        
        return count + 1;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
       int low = *max_element(weights.begin(), weights.end());
       int high = accumulate(weights.begin(), weights.end(), 0);
       int ans = 0;
        
       while(low <= high) {
         int mid = low + (high - low)/2;
           
         if(helper(weights, mid) <= days) {
             ans = mid;
             high = mid - 1;
         } 
         else {
             low = mid + 1;
         }
       }
        
       return ans;
    }
};
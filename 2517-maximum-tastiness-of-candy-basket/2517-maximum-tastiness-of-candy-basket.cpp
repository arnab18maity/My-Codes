class Solution {
public:
    
    // [1,2,5,8,13,21] -> The array needs to be sorted
    
    // Minimum Absolute Difference Should be maximized  -> Binary Search.
    
    bool helper(vector<int> &price, int minDiff, int k) {
       int count = 1, lastPicked = price[0];
        
       for(int i = 1; i < price.size(); i++) {
          if(price[i] - lastPicked >= minDiff) {
              count++;
              lastPicked = price[i];
          }  
       }
        
       return count >= k;
    }
    
    
    int maximumTastiness(vector<int>& price, int k) {
       sort(price.begin(), price.end());
       int n = price.size();
        
       int low = 0;
       int high = price[n-1] - price[0];
       
       while(low <= high) {
         int mid = low + (high - low)/2;
           
         if(helper(price,mid,k)) {
            low = mid + 1;
         }
         else {
            high = mid - 1;
         }
       }
        
       return high;
     }
};








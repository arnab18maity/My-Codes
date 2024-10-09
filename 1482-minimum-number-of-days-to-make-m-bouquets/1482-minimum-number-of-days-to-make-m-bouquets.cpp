class Solution {
public:
    int helper(vector<int> &bloomDay, int dayNo, int k) {
        int count = 0;
        int total = 0;
        
        for(int i = 0; i < bloomDay.size(); i++) {
           if(bloomDay[i] <= dayNo) {
              count++;
           }
           else {
              count = 0;
           }
            
           if(count == k) {
              total++;
              count = 0;
           }
        }
        
        return total;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m * 1LL * k > bloomDay.size()) return -1;
        
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 0;
        
        while(low <= high) {
          int mid = low + (high-low)/2;
          
          if(helper(bloomDay, mid, k) >= m) {
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
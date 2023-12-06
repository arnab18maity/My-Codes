class Solution {
public:
    bool helper(int i, vector<int> &citations) {
       int count = 0;
       for(int ind = 0; ind < citations.size(); ind++) {
           if(citations[ind] >= i) count++;
       }
        
       return count >= i;
    }
    
    int hIndex(vector<int>& citations) {
       int ans =  0;
       int low = 1, high = citations.size(); 
       
        while(low <= high) {
          int mid = (low+high)/2;
          
          if(helper(mid,citations)) {
             ans = max(ans,mid); // Can Also return it
             low = mid + 1;
          }
          else{
             high = mid - 1;
          }
        }
        
        return high;
    }
};
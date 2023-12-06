class Solution {
public:
    int hIndex(vector<int>& citations) {
/*
when you find the first element such that the value of that element is greater than or equal to the amount of elements remaining that is our ans so we return the length of array after that point. If no such element exisits return 0;
*/
       int ans = 0;
       int low = 0, high = citations.size() - 1;
        int size = citations.size(); 
        
       while(low <= high) {
          int mid = (low+high)/2;
           
          if(citations[mid] >= size - mid) {
             ans = max(ans,size - mid);
             high = mid - 1;
          }
          else{
             low = mid + 1;
          }
       }
        
        return ans;
    }
};
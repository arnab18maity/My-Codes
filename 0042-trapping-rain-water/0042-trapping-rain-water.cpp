class Solution {
public:
    int trap(vector<int>& height) {
       int n = height.size();
       vector<int> prefixMax(n), suffixMax(n);
        
       prefixMax[0] = height[0];
       for(int i = 1; i < n; i++) {
          prefixMax[i] = max(prefixMax[i-1],height[i]);
       }
        
       suffixMax[n-1] = height[n-1];
       for(int i = n-2; i >= 0; i--) {
          suffixMax[i] = max(suffixMax[i+1],height[i]);
       }
        
        int total = 0;
        for(int i = 0; i < n; i++) {
           if(prefixMax[i] > height[i] && suffixMax[i] > height[i]) {
               total += min(prefixMax[i],suffixMax[i]) - height[i];
           }
        }
        
        return total;
    }
};
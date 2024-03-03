class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
    /* int m = grid.size();
       int n = grid[0].size();
       int count = 0;
        
       for(int i = 0; i < n; i++) {
           int sum = 0;
         for(int j = 0; j < m; j++) {
             for(int k = 0; k <= i; k++) {
                sum += grid[j][k];  
             }
             
             if(sum <= k) count += 1;
             else break;
         }
       }
        
       return count;
     */   
        
      // https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/discuss/4814669/prefix-sum-2d-c/
        
       int m = grid.size();
       int n = grid[0].size();
       int count = 0;
        
       vector<vector<int>> pf(grid.begin(),grid.end());
      
       for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
             if(i >= 1) pf[i][j] += pf[i-1][j];
             if(j >= 1) pf[i][j] += pf[i][j-1];
             if(i >= 1 && j >= 1) pf[i][j] -= pf[i-1][j-1];
             
             if(pf[i][j] <= k) count++;
             else break;
           }
       }
        
       return count;
    }        
};






























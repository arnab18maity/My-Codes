class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
       int m = grid.size();
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
    }
};
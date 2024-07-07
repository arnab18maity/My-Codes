class Solution {
public:
    void preCompute(vector<vector<char>>& grid, vector<vector<int>> &arr, char ch) {
         int n = arr.size();
         int m = arr[0].size();
        
         for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
              arr[i][j] = (grid[i][j] == ch);
              if(i > 0) arr[i][j] += arr[i-1][j];
              if(j > 0) arr[i][j] += arr[i][j-1];
              if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
           }
        }

    }
    
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
//         for(int i = 0; i < m; i++) {
//            int allX = 0, allY = 0;
            
//            for(int j = 0; j < n; j++) {              
//               for(int k = 0; k <= i; k++) {
//                  if(grid[j][k] == 'X') {
//                    allX++;
//                  }
//                  if(grid[j][k] == 'Y') {
//                    allY++;
//                  }
//               }
               
//               if(allX > 0 && allX == allY) count++;
//            }
//         }
        
        vector<vector<int>> countX(n,vector<int>(m,0)), countY(n,vector<int>(m,0));
        
        preCompute(grid, countX, 'X');
        preCompute(grid, countY, 'Y');
        
        for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
              if(countX[i][j] > 0 && countX[i][j] == countY[i][j]) count++; 
           }
        }
        
        return count;
    }
};
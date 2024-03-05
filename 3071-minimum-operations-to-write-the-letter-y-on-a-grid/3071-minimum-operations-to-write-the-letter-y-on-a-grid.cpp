class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n = grid.size();
        int threshold = n/2;
        
        int zY = 0, oY = 0, tY = 0;
        int znY = 0, onY = 0, tnY= 0;
        
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
             if(i <= threshold && j == i) {
                if(grid[i][j] == 0) zY++;
                else if(grid[i][j] == 1) oY++;
                else tY++;
             }
             else if(i <= threshold && j == n-i-1) {
                if(grid[i][j] == 0) zY++;
                else if(grid[i][j] == 1) oY++;
                else tY++; 
             }
             else if(i > threshold && j == threshold) {
                if(grid[i][j] == 0) zY++;
                else if(grid[i][j] == 1) oY++;
                else tY++; 
             }
             else{
                if(grid[i][j] == 0) znY++;
                else if(grid[i][j] == 1) onY++;
                else tnY++; 
             }
          }
        }
      
     int c1Zero = oY + tY + znY + tnY;
     int c2Zero = oY + tY + znY + onY;
         
     int c1One = zY + tY + onY + tnY;
     int c2One = zY + tY + onY + znY;
         
     int c1Two = oY + zY + znY + tnY;
     int c2Two = oY + zY + onY + tnY;
         
     return min({c1Zero,c2Zero,c1One,c2One,c1Two,c2Two});
        
    }
};





























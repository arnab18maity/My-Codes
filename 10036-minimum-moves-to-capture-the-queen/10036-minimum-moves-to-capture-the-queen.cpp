class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
     // Minumum number of moves can be 1 or 2. So we have to check if
     // we can capture the queen in 1 move or not. Otherwise 2 is the answer.
     // The answer will be 1 if the queen is on the path of the rook or bishop 
     // and none of them is in between.
        
     // Check for Rook
        
        if(a == e) {
         // If the row is same with queen we have to check left & right
           int col = b;
           while(col <= 8) {
             if(a == c && col == d) break; // Bishop is in the path
             if(a == e && col == f) return 1;
             col++;
           }
            
           col = b;
           while(col > 0) {
             if(a == c && col == d) break; // Bishop is in the path
             if(a == e && col == f) return 1;
             col--;  
           }
        }
        
        if(b == f) {
         // If the column is same with queen we have to check up & down
          int row = a;
          while(row <= 8) {
            if(row == c && b == d) break; // Bishop is in the path
            if(row == e && b == f) return 1;
            row++;
          }
            
          row = a;
          while(row > 0) {
            if(row == c && b == d) break; // Bishop is in the path
            if(row == e && b == f) return 1;
            row--;  
          }
        }
        
        
        // Check for Bishop
        
        // Left Upper Diagonal
        int row = c, col = d;
        while(row > 0 && col > 0) {
           row = row - 1;
           col = col - 1;
           if(row == a && col == b) break; // Rook is in the path
           if(row == e && col == f) return 1;
        }
        
        // Right Upper Diagonal
        row = c, col = d;
        while(row > 0 && col <= 8) {
           row = row - 1;
           col = col + 1;
           if(row == a && col == b) break; // Rook is in the path
           if(row == e && col == f) return 1;
        }
        
        // Right Lower Diagonal
        row = c, col = d;
        while(row <= 8 && col <= 8) {
           row = row + 1;
           col = col + 1;
           if(row == a && col == b) break; // Rook is in the path
           if(row == e && col == f) return 1;
        }
        
        // Left Lower Diagonal
        row = c, col = d;
        while(row <= 8 && col > 0) {
           row = row + 1;
           col = col - 1;
           if(row == a && col == b) break; // Rook is in the path
           if(row == e && col == f) return 1;
        }
        
        return 2;
    }
};
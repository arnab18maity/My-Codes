class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a == e) {
           int col = b;
           while(col <= 8) {
             if(a == c && col == d) break;
             if(a == e && col == f) return 1;
             col++;
           }
            
           col = b;
           while(col > 0) {
             if(a == c && col == d) break;
             if(a == e && col == f) return 1;
             col--;  
           }
        }
        
        if(b == f) {
          int row = a;
          while(row <= 8) {
            if(row == c && b == d) break;
            if(row == e && b == f) return 1;
            row++;
          }
          row = a;
          while(row > 0) {
            if(row == c && b == d) break;
            if(row == e && b == f) return 1;
            row--;  
          }
        }
        
        int row = c, col = d;
        while(row > 0 && col > 0) {
           row = row - 1;
           col = col - 1;
           if(row == a && col == b) break;
           if(row == e && col == f) return 1;
        }
        
        row = c, col = d;
        while(row > 0 && col <= 8) {
           row = row - 1;
           col = col + 1;
           if(row == a && col == b) break;
           if(row == e && col == f) return 1;
        }
        
        row = c, col = d;
        while(row <= 8 && col <= 8) {
           row = row + 1;
           col = col + 1;
           if(row == a && col == b) break;
           if(row == e && col == f) return 1;
        }
        
        row = c, col = d;
        while(row <= 8 && col > 0) {
           row = row + 1;
           col = col - 1;
           if(row == a && col == b) break;
           if(row == e && col == f) return 1;
        }
        
        return 2;
    }
};
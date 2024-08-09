class neighborSum {
private:
   vector<vector<int>> grid;
public:
    neighborSum(vector<vector<int>>& grid) {
       this -> grid = grid; 
    }
    
    int adjacentSum(int value) {
        int sum = 0;
        int n = grid.size();
        int i = -1, j = -1;
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == value) {
                    i = r;
                    j = c;
                    break;
                }
            }
            
            if(i != -1) break;
        }
        
        if(i-1 >= 0) sum += grid[i-1][j];
        if(i+1 <= n-1) sum += grid[i+1][j];
        if(j-1 >= 0) sum += grid[i][j-1];
        if(j+1 <= n-1) sum += grid[i][j+1];
        
        return sum;
    }
    
    int diagonalSum(int value) {
        int sum = 0;
        int n = grid.size();
        int i = -1, j = -1;
        
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == value) {
                    i = r;
                    j = c;
                    break;
                }
            }
            
            if(i != -1) break;
        }
        
        if(i-1 >= 0 && j-1 >= 0) sum += grid[i-1][j-1];
        if(i-1 >= 0 && j+1 <= n-1) sum += grid[i-1][j+1];
        if(i+1 <= n-1 && j+1 <= n-1) sum += grid[i+1][j+1];
        if(i+1 <= n-1 && j-1 >= 0) sum += grid[i+1][j-1];
        
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
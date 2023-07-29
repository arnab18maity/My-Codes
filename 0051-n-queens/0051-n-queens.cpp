class Solution {
public:
    
    bool isSafe(vector<string> &board,int row,int col,int n)
    {
        // same row check
        int x = row;
        int y = col;
        
       while(y >= 0){
           if(board[x][y] == 'Q')
             return false;
           y--;
       }
        
        // upper diagonal check
        x = row;
        y = col;
        
       while(x >= 0 && y >= 0){
           if(board[x][y] == 'Q')
             return false;
           y--;
           x--;
       }
        
    //Lower diagonal check    
       x = row;
       y = col;
        
       while(x < n && y >= 0){
           if(board[x][y] == 'Q')
             return false;
           y--;
           x++;
       }
        
        return true;
    }
    
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        // base case
        if(col == n)
        {
           ans.push_back(board);
           return;
        }
        
        // solve 1 case rest recursion will take care
        for(int row = 0; row < n; row++){
            if(isSafe(board,row,col,n))
            {
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(0,board,ans,n);
        return ans;
    }
};
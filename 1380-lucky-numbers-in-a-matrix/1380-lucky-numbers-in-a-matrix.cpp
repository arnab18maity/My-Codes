class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
       
        vector<int> row(n,0), col(m,0);
        vector<int> lucky;
        
        for(int i = 0; i < n; i++) {
           int mini = INT_MAX;
           for(int j = 0; j < m; j++) {
             mini = min(mini,matrix[i][j]); 
           }
           
            row[i] = mini;
        }
        
        for(int j = 0; j < m; j++) {
          int ma = 0;
          for(int i = 0; i < n; i++) {
             ma = max(ma,matrix[i][j]); 
          }
          
           col[j] = ma;
        }
        
        for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
             if(matrix[i][j] == row[i] && matrix[i][j] == col[j]) {
                lucky.push_back(matrix[i][j]);
             } 
           }
        }
        
        return lucky;
    }
};
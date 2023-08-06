class Solution {
public:
    void solve(int i,int j,vector<vector<int>>& matrix,int m,int n) {
        for(int a = i-1; a >= 0; a--){
            matrix[a][j] = 0;
        }
         for(int a = i+1; a < m; a++){
            matrix[a][j] = 0;
        }
        
         for(int a = j-1; a >= 0; a--){
            matrix[i][a] = 0;
        }
        
         for(int a = j+1; a < n; a++){
            matrix[i][a] = 0;
        }
        
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        map <pair<int,int>,int> isZero;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    isZero[{i,j}] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isZero[{i,j}] == 1){
                  solve(i,j,matrix,m,n);
                }
            }
        }
        
        
    }
};
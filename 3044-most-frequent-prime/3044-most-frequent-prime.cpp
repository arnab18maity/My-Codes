class Solution {
public:
    bool isPrime(int num) {
      for(int div = 2; div <= (int)sqrt(num); div++) {
          if(num % div == 0) return false;
      }
        
      return true;
    }
    
    void visit(vector<vector<int>>& mat, int row, int col, int delRow, int delCol, int num, map<int,int>& mp, int &maxi) {
       int m = mat.size(), n = mat[0].size();
        
       if(row < 0 || col < 0 || row >= m || col >= n) return;
       if((row+delRow < 0 || col+delCol < 0) || (row+delRow >= m || col+delCol >= n)) return;
        
       int number =  num + mat[row+delRow][col+delCol];
        
       if(number > 10 && isPrime(number)) {
         mp[number]++;
         maxi = max(maxi,mp[number]);
       } 
        
       visit(mat, row+delRow, col+delCol, delRow, delCol, number*10,mp,maxi);
    }
    
    int mostFrequentPrime(vector<vector<int>>& matrix) {
      int delRow[] = {-1,-1,0,+1,+1,+1,0,-1};
      int delCol[] = {0,+1,+1,+1,0,-1,-1,-1};
      
      int m = matrix.size(), n = matrix[0].size();
      int maxi = 0;
      map<int,int> mp;
       
      for(int i = 0; i < m; i++) {
         for(int j = 0; j < n; j++) {
            int num  = matrix[i][j];
            for(int k = 0; k < 8; k++) {
               visit(matrix,i,j,delRow[k],delCol[k],num*10,mp,maxi);
            }
         }
      }
        
      int ans = -1;
      for(auto it : mp) {
        if(it.second == maxi) {
          ans = max(ans,it.first);
        }  
      }
        
      return ans;
    }
};













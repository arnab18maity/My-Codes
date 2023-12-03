class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
       int n = matrix.size();
       if(matrix == target) return true;
       for(int cnt = 1; cnt <= 3; cnt++) {
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }

            for(int i = 0; i < n; i++) {
               reverse(matrix[i].begin(),matrix[i].end());
            }

            if(matrix == target) return true;
       }
        
        return false;
    }
};
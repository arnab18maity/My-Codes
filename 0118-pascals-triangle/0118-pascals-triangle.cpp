class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> setrows;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = setrows[i - 1][j] + setrows[i - 1][j - 1];
            }
            setrows.push_back(row);
        }
        
        return setrows;      
    }
};
class Solution {
public:
    int largestRectangle(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
           while(!st.empty() && heights[st.top()] > heights[i]) {
               int elementIndex = st.top();
               st.pop();
               int nseIndex = i, pseIndex = st.empty() ? -1 : st.top();
               maxArea = max(maxArea, heights[elementIndex]*(nseIndex-pseIndex-1));
           }
            
           st.push(i);
        }
        
        while(!st.empty()) {
           int elementIndex = st.top();
           st.pop();
           int nseIndex = n;
           int pseIndex = st.empty() ? -1 : st.top();
           maxArea = max(maxArea, heights[elementIndex]*(nseIndex-pseIndex-1));
        }
        
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> histogram(n, vector<int>(m,0));
        
        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
               sum += matrix[i][j] - '0';
               if(matrix[i][j] == '0') sum = 0;
               histogram[i][j] = sum;
            }
        }
        
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
           maxArea = max(maxArea, largestRectangle(histogram[i]));
        }
        
        return maxArea;
    }
};
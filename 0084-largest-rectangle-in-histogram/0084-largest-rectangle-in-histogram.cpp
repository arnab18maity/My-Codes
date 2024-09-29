class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};
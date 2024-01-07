class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       int n = dimensions.size();
       double maxD = 0;
       int maxArea = 0;
        
       for(int i = 0; i < n; i++) {
         int length = dimensions[i][0];
         int width = dimensions[i][1];
         int area = length * width;
         double diagonal = (double)sqrt((length*length) + (width*width));
       
         if(diagonal == maxD) {
            maxArea = max(maxArea,area);
            maxD = diagonal;
         }
         else if(diagonal > maxD) {
            maxArea = area;
            maxD = diagonal;
         }
       }
        
        return maxArea;
    }
};
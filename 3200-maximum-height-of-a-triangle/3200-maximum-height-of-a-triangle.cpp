class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int maxi = max(red,blue);
        int mini = min(red,blue);
        
        int height1 = 0, height2 = 0, i = 1;
        
        while(maxi > 0 || mini > 0) {
           if(i % 2) {
             if(mini < i) break;
             mini -= i;
             i++;
             height1++;
           }
           else{
             if(maxi < i) break;
             maxi -= i;
             i++;
             height1++;
           }
        }
        
        
        maxi = max(red,blue);
        mini = min(red,blue);
        i = 1;
        
        while(maxi > 0 || mini > 0) {
           if(i % 2) {
             if(maxi < i) break;
             maxi -= i;
             i++;
             height2++;
           }
           else{
             if(mini < i) break;
             mini -= i;
             i++;
             height2++;
           }
        }
        
        
        return max(height1,height2);
    }
};
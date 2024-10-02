class Solution {
public:
    int solve(int curr, int clip, int num) {
       if(curr == num) return 0;
       if(curr > num) return 1e7;
        
       // Paste
       int paste = 1 + solve(curr + clip, clip, num);
        
       // Copy & Paste  // There is no point of only copying
       int copyandpaste = 2 + solve(curr+curr, curr, num);
       
        
       return min(copyandpaste,paste);
    }
    
    int minSteps(int n) {
       if(n == 1) return 0;
       return 1 + solve(1,1,n); 
    }
};
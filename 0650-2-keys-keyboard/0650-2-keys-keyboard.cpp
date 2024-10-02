class Solution {
public:
    int solve(int curr, int clip, int num) {
       if(curr == num) return 0;
       if(curr > num) return 1e7;
        
       int copy = (curr != clip) ? 1 + solve(curr, curr, num) : 1e7;
       int paste = (clip > 0) ? 1 + solve(curr + clip, clip, num) : 1e7;
        
       return min(copy,paste);
    }
    
    int minSteps(int n) {
       return solve(1,0,n); 
    }
};
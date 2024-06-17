class Solution {
public:
    int scoreOfString(string s) {
       int prev = s[0] - '0';
        
       int i = 1, score = 0;
        
       while(i < s.size()) {
         int curr = s[i] - '0';
         score += abs(prev - curr);
         prev = curr;
         i++;
       }
        
       return score;
    }
};
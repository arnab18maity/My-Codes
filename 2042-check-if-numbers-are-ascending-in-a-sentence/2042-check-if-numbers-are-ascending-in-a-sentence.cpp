class Solution {
public:
    bool areNumbersAscending(string s) {
       int curr = 0, prev = -1, n = s.size();
        
       for(int i = 0; i < n; i++) {
          if(s[i] >= '0' && s[i] <= '9') {
            if(i < n-1 && s[i+1] >= '0' && s[i+1] <= '9') {
                prev = curr;
                curr = (s[i] - '0')*10 + (s[i+1] - '0');
                i++;
            }
            else{
                 prev = curr;
                 curr = (s[i] - '0');
            }
          }
          
          if(prev >= curr) return false;
       }
        
        return true;
    }
};
class Solution {
public:
    string makeGood(string s) {
        if(s.size() <= 1) return s;
        int n = s.size();
        
        for(int i = 0; i < n-1; i++){
            if(tolower(s[i]) == tolower(s[i+1])){
                if((islower(s[i]) && isupper(s[i+1])) || (isupper(s[i]) && islower(s[i+1]))){
                    s.erase(i,2);
                    i = -1;
                    n -= 2;
                }
            }
        }
        
        return s;
    }
};
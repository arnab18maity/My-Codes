class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows == 1) return s;
       vector<string> vec(numRows,"");
       int j = 0, flag = -1;
       
       for(int i = 0; i < s.size(); i++) {
          //If the current row is first row or last row then only we have to
          // change the direction
          if(j == numRows-1 || j == 0) flag *= -1;
           
          vec[j] += s[i];
           
          j += flag;
       }
        
       string res;
       for(auto it : vec) res += it;
       return res;
    }
};
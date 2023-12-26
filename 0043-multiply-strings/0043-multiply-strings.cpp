class Solution {
public:
    string multiply(string num1, string num2) {
       if (num1 == "0" || num2 == "0") return "0";
       int n = num1.size(), m = num2.size();
        
       // Maximum size of the result of multiplication can be (n+m)
       vector<int> res(n+m,0);
        
       for(int i = m-1; i >= 0; i--) {
          for(int j = n-1; j >= 0; j--) {
              res[i+j+1] += (num1[j] - '0') * (num2[i] - '0');
              res[i+j] += res[i+j+1]/10;
              res[i+j+1] %= 10;
          }
       }
       
       string ans;
       int i = 0;
        
       // Remove if there exist any leading zeroes
       while(res[i] == 0) i++;
        
       // Convert the remaining array to string 
       while(i < n+m) {
         ans += to_string(res[i++]); 
       }
        
       return ans;
    }
};
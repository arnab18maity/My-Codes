class Solution {
public:
    string multiply(string num1, string num2) {
       if (num1 == "0" || num2 == "0") return "0";
       int n = num1.size(), m = num2.size();
        
       // Maximum size of the result of multiplication can be (n+m)
       string res(n+m, '0');
        
       for(int i = m-1; i >= 0; i--) {
          for(int j = n-1; j >= 0; j--) {
              int sum = (num1[j] - '0') * (num2[i] - '0') + (res[i+j+1] - '0');
              res[i+j+1] = (sum % 10) + '0';
              res[i+j] += sum/10;
          }
       }
      
       int i = 0;        
       // Remove if there exist any leading zeroes
       while(res[i] == '0') i++;
    
       return res.substr(i);
    }
};
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1 == "0") return num2;
        if(num2 == "0") return num1;
        
        int n = num1.size(), m = num2.size();
        int s = max(n,m) + 1;
        string ans(s,'0');
        
        int i = n-1, j = m-1, carry = 0, index = s-1;
    
        while(i >= 0 && j >= 0) {
          int sum = (num1[i--] - '0') + (num2[j--] - '0') + carry;
          ans[index--] = (sum%10) + '0';
          carry = sum / 10;
        }
        
        while(i >= 0) {
          int sum = (num1[i--] - '0') + carry;
          ans[index--] = (sum%10) + '0';
          carry = sum / 10; 
        }
        
        while(j >= 0) {
          int sum = (num2[j--] - '0') + carry;
          ans[index--] = (sum%10) + '0';
          carry = sum / 10; 
        }
        
        if(carry) ans[index] = carry + '0';
        
        int k = 0;
        while(ans[k] == '0') k++;
        return ans.substr(k);
    }
};
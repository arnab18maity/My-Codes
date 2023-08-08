class Solution {
public:
    string addBinary(string a, string b) {
        
        int la = a.size();
        int lb = b.size();
        
        if(la == 0){
            return b;
        }
        if(lb == 0){
            return a;
        }
        
        int v1,v2,carry = 0,sum = 0;
        string ans;
        
        for(int i = la - 1,j = lb - 1; i >= 0 || j >= 0 || carry != 0; i--,j--)
        {
            v1 = 0;
            v2 = 0;
            
            if(i >= 0){
              v1 = a[i] - '0';
            }
            
            if(j >= 0){
               v2 = b[j] - '0';
            }
            
            sum = v1 + v2 + carry;
            carry = sum/2;          
            
            ans += to_string(sum % 2);
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
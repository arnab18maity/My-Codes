class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0)
        {
          return false;  
        }
        int temp=x;
        long rev=0;
        while(x>0)
        {
          long a = x%10;
          rev = rev*10 + a;
          x = x/10;  
        }
        if(temp==rev)
        {
            return true;
        }
        else{
            return false;
        } 
    }
};
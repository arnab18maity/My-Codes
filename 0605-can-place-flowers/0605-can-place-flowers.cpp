class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        
        int count = 0;
        int s = flowerbed.size();
        
        if(s == 1) {
          return (n == 1 && flowerbed[0] == 0);
        }
        
        for(int i = 0; i < s; i++) {
           if(i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
              count++;
              flowerbed[i] = 1;
           }
           else if(i == s-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0) {
               count++;
               flowerbed[i] = 1;
           }
           else if(i != 0 && i != s-1 && flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
               count++;
               flowerbed[i] = 1;
           }
        }
        
        return count >= n;
    }
};
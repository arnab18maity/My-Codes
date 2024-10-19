class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = accumulate(apple.begin(), apple.end(), 0);
        int count = 0;
        sort(capacity.rbegin(), capacity.rend());
        
        for(int i = 0; i < capacity.size(); i++) {
           if(totalApple > 0) {
              count++;
              totalApple -= capacity[i];
           }
           else break;
        }
        
        return count;
    }
};
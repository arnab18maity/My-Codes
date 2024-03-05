class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
       int n = prices.size();
       vector<int> nse(n,0);
       nse[n-1] = 0;
       stack<int> st;
       st.push(prices[n-1]);
        
       int i = n-2;
       while(i >= 0) {
          while(!st.empty() && st.top() > prices[i]) {
              st.pop();
          }
           
          if(st.empty()) {
            nse[i] = 0;
            st.push(prices[i]);
          }
          else{
            nse[i] = st.top();
            st.push(prices[i]);
          }
           
          i--;
       }
        
       vector<int> answer(n);
        
       for(int i = 0; i < n; i++) {
           answer[i] = prices[i] - nse[i];
       }
        
       return answer;
    }
};
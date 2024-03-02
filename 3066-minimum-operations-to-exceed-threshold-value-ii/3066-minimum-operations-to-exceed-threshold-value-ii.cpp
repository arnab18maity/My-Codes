class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
   /*  
       int count = 0; 
       int start = 0;
       vector<long long> temp(nums.begin(),nums.end());
        
       sort(temp.begin(),temp.end()); 
        
       while(temp.size() - start > 1 && temp[start] < k) {
          long long x = temp[start];
          long long y = temp[start+1];
          long long num = min(x,y)*2 + max(x,y);
          if(num < k) {
              temp.push_back(num);
              sort(temp.begin(),temp.end());
          }
          start += 2;
          count++;
       }
        
       return count;
     
    */
        
      priority_queue<long long, vector<long long>, greater<long long>>pq(nums.begin(),nums.end());
      int count = 0;
        
      while(pq.top() < k) {
         long long n1 = pq.top();
          pq.pop();
         long long n2 = pq.top();
          pq.pop();
         
         long long num = min(n1,n2)*2 + max(n1,n2);
         pq.push(num);
         count++;
      }    
        
      return count;
           
    }
};












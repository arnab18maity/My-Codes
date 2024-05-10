class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       vector<pair<float,pair<int,int>>> nums;
       int n = arr.size(); 
        
       for(int i = 0; i < n; i++) {
           for(int j = i+1; j < n; j++) {
              float frac = arr[i]/(arr[j]*1.0);
              pair<float,pair<int,int>> p;
              p.first = frac;
              p.second.first = i;
              p.second.second = j;
              nums.push_back(p);
           }
       }
        
       sort(nums.begin(),nums.end());
        
       pair<float,pair<int,int>> p = nums[k-1];
       int ind1 = p.second.first;
       int ind2 = p.second.second;
        
        
       return {arr[ind1],arr[ind2]};       
    }
};
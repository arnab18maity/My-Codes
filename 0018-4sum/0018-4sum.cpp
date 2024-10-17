class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0; i < n - 3; i++) {
            
            if(i != 0 && nums[i] == nums[i-1]) continue;
           
            for(int j = i + 1; j < n - 2; j++) {
                
               if(j > i + 1 && nums[j] == nums[j-1]) continue;
                
               int k = j + 1;
               int m = n - 1;
            
                while(k < m) {
                   long long sum = nums[i] + 0LL + nums[j] + nums[k] + nums[m];
                   if(sum > target) m--;
                   else if(sum < target) k++;
                   else {
                      ans.push_back({nums[i], nums[j], nums[k], nums[m]});
                      k++;
                      m--;
                      while(k < m && nums[k] == nums[k-1]) k++;
                      while(k < m && nums[m] == nums[m+1]) m--;
                   }
                } 
            }
            
        }
        
        return ans;
    }
};
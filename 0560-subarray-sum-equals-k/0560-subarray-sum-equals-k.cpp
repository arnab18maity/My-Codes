class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];            
            int rem = sum - k;
            count += prefixSum[rem];     
            prefixSum[sum]++;
        }
       
        return count;  
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0] == k;
        
        int sum = 0, subCount = 0;
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];            
            int rem = sum - k;
            if(prefixSum.find(rem) != prefixSum.end()) subCount += prefixSum[rem];
            
            prefixSum[sum]++;
        }
       
        return subCount;
    }
};
class Solution {
public:
    int maxOfDigit(int val){
        int max = 0;
        while(val > 0)
        {
            int digit = val % 10;
            if(digit > max) max = digit;
            val = val / 10;
        }
        
        return max;
    }
    
    int maxSum(vector<int>& nums) {
        map<int,int> mp;
        int ans = -1;
        for(int i = 0; i < nums.size() ; i++) {
            int maxi = maxOfDigit(nums[i]);
            if(mp[maxi] == 0){
                mp[maxi] = nums[i];
            }
            else{
                int v = mp[maxi] + nums[i];
                if(nums[i] > mp[maxi]) mp[maxi] = nums[i];
                ans = max(ans,v);
            }
        }
        
        return ans;
    }
};
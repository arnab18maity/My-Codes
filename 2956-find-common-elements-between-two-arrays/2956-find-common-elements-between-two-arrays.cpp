class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int cnt1 = 0, cnt2 = 0;
        unordered_map<int,int> mp1, mp2;
        int n = nums1.size(), m = nums2.size();
        
        for(int i = 0; i < n; i++) {
            mp1[nums1[i]]++;
        }
        
        for(int i = 0; i < m; i++) {
            mp2[nums2[i]]++;
        }
        
        for(int i = 0; i < n; i++) {
            if(mp2.find(nums1[i]) != mp2.end()) cnt1++;
        }
        
        for(int i = 0; i < m; i++) {
            if(mp1.find(nums2[i]) != mp1.end()) cnt2++;
        }
        
        return {cnt1,cnt2};
    }
};
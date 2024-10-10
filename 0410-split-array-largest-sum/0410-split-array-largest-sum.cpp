class Solution {
public:
int helper(vector<int> &arr, int num) {
   int count = 1, currPages = 0;

   for(int i = 0; i < arr.size(); i++) {
        if(currPages + arr[i] <= num) {
          currPages += arr[i];
        }
        else {
           count++;
           currPages = arr[i];
        }
    } 

    return count;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0); 
    int ans = INT_MAX;
    

    while(low <= high) {
        int mid = low + (high-low)/2;
        
        int res = helper(arr,mid);
        
        if(res <=  m) {
          ans = mid;
          high = mid - 1;
        }
        else {
          low = mid + 1;
        }
    }

    return ans;
}

    int splitArray(vector<int>& nums, int k) {
       return findPages(nums, nums.size(), k);
    }
};




















class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = nums.size();
        int countA = 0,countB = 0,countC = 0;
        for(int i = 0; i < s ; i++){
            if(nums[i] == 0){
                countA++;
            }
            else if(nums[i] == 1){
                countB++;
            }
            else{
                countC++;
            }
        }
        
        for(int i = 0; i < s ; i++){
            if(countA > 0){
                nums[i] = 0;
                countA--;
                continue;
            }
            else if(countB > 0){
                nums[i] = 1;
                countB--;
                continue;
            }
            else{
                nums[i] = 2;
            }
            
        }
    }
};
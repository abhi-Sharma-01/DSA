class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }
        
        int maxLength = 1;
        int curr_LenInc = 1, curr_LenDec = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                curr_LenInc++;
                curr_LenDec = 1; 
            } else if (nums[i] < nums[i - 1]) {
                curr_LenDec++;
                curr_LenInc = 1;  
            } else {
                curr_LenInc = 1;
                curr_LenDec = 1;
            }
            maxLength = max({maxLength, curr_LenInc, curr_LenDec});
        }
        return maxLength;
    }
};

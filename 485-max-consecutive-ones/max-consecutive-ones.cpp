class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                maxi = max(maxi, right - left);
                left = i + 1; 
            }
            right++;
        }
        maxi = max(maxi, right - left);

        return maxi;
    }
};

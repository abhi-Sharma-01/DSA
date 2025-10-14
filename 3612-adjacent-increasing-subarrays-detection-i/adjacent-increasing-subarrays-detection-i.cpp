class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1, precount = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++count;
            } else {
                precount = count;
                count = 1;
            }
            res = max(res, min(precount, count));
            res = max(res, count / 2);
        }
        return res >= k;       
    
    }
};
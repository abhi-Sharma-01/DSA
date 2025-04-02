typedef long long ll;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll maxResult = 0;
        ll maxDiff = 0;

        for (int j = 1; j < n - 1; ++j) {
            for (int i = 0; i < j; ++i) {
                maxDiff = max(maxDiff, (ll)nums[i] - nums[j]);
            }
            for (int k = j + 1; k < n; ++k) {
                maxResult = max(maxResult, maxDiff * nums[k]);
            }
        }
        return maxResult;
    }
};
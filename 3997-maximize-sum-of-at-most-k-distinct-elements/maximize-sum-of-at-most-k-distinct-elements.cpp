class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend()); // desc order
        vector<int> result;
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.find(num) == seen.end()) {
                result.push_back(num);
                seen.insert(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
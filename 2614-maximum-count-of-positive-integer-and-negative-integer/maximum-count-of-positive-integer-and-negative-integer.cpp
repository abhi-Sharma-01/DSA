class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pC = 0, nC = 0;
        for (int i : nums) {
            pC+= i > 0;
            nC += i < 0;
        }
        return max(pC,nC);
    }
};
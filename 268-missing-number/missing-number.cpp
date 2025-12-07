class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int MaxSum = (n*(n+1))/2;

        return MaxSum - accumulate(nums.begin(),nums.end(),0);
    }
};
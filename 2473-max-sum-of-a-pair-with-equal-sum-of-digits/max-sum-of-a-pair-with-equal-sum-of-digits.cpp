class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        // note max possible sum of digit = 81 i.e 999999999
        int maxArr[82] = {
            0}; // Array to store max number for each digit sum (0-81)
        int maxSum = -1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sum = digitSum(num);

            // If a number with the same digit sum exists, update maxSum
            if (maxArr[sum] > 0) {
                maxSum = max(maxSum, maxArr[sum] + num);
            }

            // Store the maximum number for this digit sum
            maxArr[sum] = max(maxArr[sum], num);
        }
        return maxSum;
    }
};
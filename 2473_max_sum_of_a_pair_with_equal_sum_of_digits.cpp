class Solution {
public:
    // phley digit sum ka ek function so that we can find each index sum
    int digitSum(int a) {
        int sum = 0;
        while (a > 0) {
            sum += a % 10;
            a /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        // We need to create a array jaha ham all possible size sum pata ka sake
        // note max possible sum of digit = 81 i.e 999999999 
        int maxArr[82] = {0}; // Array to store max number for each digit sum (0-81)
        int maxSum = -1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sum = digitSum(num);
        //for ex if curr num = 24 i.e 2+4 =6 now we need to check whether their already a pair having digit sum 6 exist or not so that they can be pair if multiple are their we have to select max in them and so on...like 51 , 60....
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
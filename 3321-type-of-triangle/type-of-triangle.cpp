class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        // Triangle Inequality Theorem: Sum of any two sides must be greater than the third
        if (a + b <= c || b + c <= a || a + c <= b) {
            return "none";  // Not a valid triangle
        }

        // Check for Equilateral
        if (a == b && b == c) {
            return "equilateral";
        }

        // Check for Isosceles
        if (a == b || b == c || a == c) {
            return "isosceles";
        }

        // If all sides are different
        return "scalene";
    }
};

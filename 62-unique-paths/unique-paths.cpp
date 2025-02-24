class Solution {
public:
    const int MOD = 2000000000; // Modulus value

    long long comb(int n, int k) {
        long long result = 1;
        if (k > n - k) k = n - k;
        for (int i = 0; i < k; ++i) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result % MOD;
    }

    int uniquePaths(int m, int n) {
        return comb(m + n - 2, m - 1);
    }
};

class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long factorial(long long n) {
        long long res = 1;
        for (long long i = 1; i <= n; i++)
            res = (res * i) % MOD;
        return res;
    }
    int countPermutations(vector<int>& complx) {
        int n = complx.size();
        long long mn = complx[0];
        for (int i = 1; i < n; i++) {
            if (mn >= complx[i]) {
                return 0;
            }
            mn = min(mn, (long long)complx[i]);
        }
        return factorial(n - 1);
    }
};
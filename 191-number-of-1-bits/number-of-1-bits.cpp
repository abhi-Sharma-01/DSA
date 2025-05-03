class Solution {
public:
    int hammingWeight(int n) {
        // M1- using STL 
        int cnt = __builtin_popcount(n);
        return cnt;

    }
};
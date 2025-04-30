class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = n % 2;

            res = res + bit * pow(2, i);

            n /= 2;
        }
        return res;
    }
};
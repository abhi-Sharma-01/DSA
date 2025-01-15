class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int num2Bits = 0;
        for (int i = 0; i < 32; ++i) {
            if (num2 & (1 << i)) {
                ++num2Bits;
            }
        }
        int num1Bits[32];
        int num1Count = 0;        
        for (int i = 0; i < 32; ++i) {
            if (num1 & (1 << i)) {
                num1Bits[num1Count++] = i;
            }
        }
        int result = 0;
        for (int i = num1Count - 1; i >= 0 && num2Bits > 0; --i) {
            result |= (1 << num1Bits[i]);
            --num2Bits;
        }
        for (int i = 0; i < 32 && num2Bits > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                --num2Bits;
            }
        }        
        return result;
    }
};

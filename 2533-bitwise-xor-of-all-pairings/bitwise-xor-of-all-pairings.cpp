class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        
        for (int i = 0; i < nums1.size(); i++) {
            xor1 ^= nums1[i];
        }
        
        for (int j = 0; j < nums2.size(); j++) {
            xor2 ^= nums2[j];
        }
        
        int result = 0;
        
        if (nums1.size() % 2 != 0) {
            result ^= xor2;
        }
        
        if (nums2.size() % 2 != 0) {
            result ^= xor1;
        }
        
        return result;
    }
};

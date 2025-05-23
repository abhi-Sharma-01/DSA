class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k = k%n;
        int l = (n-k)%n;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = nums[(l + i) % n];
        }
        nums = res;
    }

};
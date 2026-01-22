class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lmax = height[l];
        int rmax = height[r];
        int wtr = 0;

        while (l < r) {
            if (lmax < rmax) {
                l++;
                lmax = max(lmax, height[l]);
                wtr += lmax - height[l];
            } else {
                r--;
                rmax = max(rmax, height[r]);
                wtr += rmax - height[r];
            }
        }

        return wtr;        
    }
};
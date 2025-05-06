class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            int sum = 0;
            for(auto num : nums) {
                int n = (num >> i);
                if((n & 1) == 1) {
                    sum++;
                }
            }
            sum = sum % 3;// to get the unique number
            
            ans = (ans << 1);
            if(sum) {
                ans += 1;
            }
        }
        return ans;
    }
};

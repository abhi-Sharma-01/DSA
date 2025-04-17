class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0, r= n-1;
        int pairs =0;
        for(int i=0;i<n-1;i++){
            for(int j =i+1;j<n;j++){
                if (nums[i] == nums[j] && i * j % k == 0){
                    ++pairs;
                }
            }
        }
        return pairs;
    }
};
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int fSmall=INT_MAX,sSmall=INT_MAX;
        for (int i=1;i<n;i++){
            if (nums[i]<fSmall){
                sSmall=fSmall;
                fSmall=nums[i];
                continue;
            }
            if (nums[i]<sSmall)
                sSmall=nums[i];
        }
        return nums[0]+fSmall+sSmall;
    }
};
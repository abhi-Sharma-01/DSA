class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
            continue;
        }
        int left =0, right = n-1;
        while(left<right){
            if(nums[left]!=0){
                left++;
            }
            if(nums[left]==0){
                for(int i=left;i<n-1;i++){
                    nums[i]=nums[i+1];
                }
                nums[right]=0;
                right--;
            }
        }
        return nums;
    }
};
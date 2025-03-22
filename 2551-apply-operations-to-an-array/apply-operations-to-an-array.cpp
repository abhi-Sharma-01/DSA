class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        // Method 2
        int n = nums.size();
         for(int i =0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;
            }
        }
        vector<int> ans(n, 0);// initalise all element by 0 taaki we need not to enter in last
        int pos = 0; 
        for (int num : nums) {
            if (num != 0) {
                ans[pos++] = num; 
            }
        }
        return ans;

        //Method 1
        // int n = nums.size();
        // for(int i =0;i<n-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         nums[i]=2*nums[i];
        //         nums[i+1]=0;
        //     }
        //     continue;
        // }
        // int left =0, right = n-1;
        // while(left<right){
        //     if(nums[left]!=0){
        //         left++;
        //     }
        //     if(nums[left]==0){
        //         for(int i=left;i<n-1;i++){
        //             nums[i]=nums[i+1];
        //         }
        //         nums[right]=0;
        //         right--;
        //     }
        // }
        // return nums;
    }
};
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Approach - 1  //  Binary Search
        int n = nums.size();
        int low =0, high = n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high = mid-1;
            }else if(nums[mid]<target){
                low = mid+1;
            }
        }
        return low;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0,high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }
            // Here, we are checking if the left-side array is sorted or not
            if(nums[low]<=nums[mid]){
                if(nums[mid]>target && nums[low]<=target ){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(nums[mid]< target && target <= nums[high]){
                    low = mid +1;
                }else{
                    high = mid -1;
                }
            }
        }
        return -1;
        
    }
};
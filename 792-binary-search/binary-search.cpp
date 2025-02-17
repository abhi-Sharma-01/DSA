class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Approach -1 // Linear Search
            // Iterating array 
            // find tagret in the array return index or else return -1 if not found


        //Approach -2 // Binary Search
          int low =0,high = nums.size()-1;
          while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }            
          }
          return -1;

    }
};
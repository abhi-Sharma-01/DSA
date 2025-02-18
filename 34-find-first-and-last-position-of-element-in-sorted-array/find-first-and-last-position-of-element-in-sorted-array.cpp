class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // Approach -1 (Two-Pointer)
        int i=0, j = nums.size()-1;
        vector<int> res(2,-1);
        while(i<=j && nums[i]!=target){
            i++;
        }
        while(i<=j && nums[j]!=target){
            j--;
        }
        if(i<=j){
            res[0]=i;
            res[1]=j;
        }
        return res;
    }
};
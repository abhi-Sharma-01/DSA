class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int indx = n-1;
        int left = 0,right = n-1;
        while(indx>=0){
            if(abs(nums[left])>abs(nums[right])){
                ans[indx]=(nums[left]*nums[left]);
                left++;
            }else{
                ans[indx]= (nums[right]*nums[right]);
                right--;
            }
            indx--;
        }
        return ans;
    }
};
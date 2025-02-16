class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int good_sum =0;
        for(int i =0;i<n;i++){
            int flag = 1;
            if((i-k>=0 && nums[i] <= nums[i-k]) || (i+k<n && nums[i] <= nums[i+k])){
                flag = 0 ; // i.e 
            }
            if(flag==1){
                good_sum += nums[i];
            }            
        }
        return good_sum;
    }
};
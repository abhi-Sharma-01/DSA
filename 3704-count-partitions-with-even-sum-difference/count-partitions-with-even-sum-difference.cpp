class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum =0;
        for(int x:nums){
            sum += x;
        }
        int sumL=0;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            sumL += nums[i];
            sum -= nums[i];
            if(abs(sum-sumL)%2 == 0){
                cnt++;
            }
        }
        return cnt;
    }
};
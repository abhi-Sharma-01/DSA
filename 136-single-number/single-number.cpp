class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int first = 0;
        for(int i=0;i<nums.size();i++){
            first=first^nums[i]; 
        }
        return first;
    }
};
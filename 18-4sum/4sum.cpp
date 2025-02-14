class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> set;
        vector<vector<int>> result;

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long newtarget = (long)target - (long)nums[i] -(long)nums[j];
                int left = j+1, right = n-1;
                while(left<right){
                    if(nums[left]+nums[right] < newtarget){
                        left++;
                    }else if(nums[left]+nums[right] > newtarget){
                        right--;
                    }else{
                        set.insert({nums[i],nums[j],nums[left],nums[right]});
                        right--;
                        left++;
                    }
                }
            }
        }
        for(auto it : set){
            result.push_back(it);
        }
        return result;

    }
};
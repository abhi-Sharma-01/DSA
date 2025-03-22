class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> map(n + 1, 0);
        for(int i=0;i<n;i++){
            map[nums[i]]=1;
        }
        int indx=-1;
        for(int i=0;i<=n;i++){
            if(map[i]==0){
                return i;
            }
        }      
        return -1;
    }
};
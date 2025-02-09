class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long total_pair = (long long) n*(n-1)/2;
        for(int i=0;i<n;i++){
            nums[i] = nums[i]-i;
        }
        sort(nums.begin(),nums.end());
        long long good_pair=0;
        long long count=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                count++;
            }else{
                good_pair += (count*(count-1))/2;
                count=1; 
            }
        }
        good_pair += (count*(count-1))/2;
        return total_pair - good_pair;
    }
};
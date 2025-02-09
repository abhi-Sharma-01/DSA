class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        // Approach-1

        // int count =0;         
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(i<j & j-i!=nums[j]-nums[i]){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //Approach-2 (Note : We can manipulate the nums[i]-i!=nums[j]-j  )
        
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
                count=1; // agar value change hota hai then we need it initialize count again from 1 to count next equal values
            }
        }
        good_pair += (count*(count-1))/2;// final if last element was counted so we need to update
        return total_pair - good_pair;
    }
};
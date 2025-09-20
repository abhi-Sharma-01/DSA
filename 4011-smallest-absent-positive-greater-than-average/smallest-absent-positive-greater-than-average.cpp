class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        long long avg = (float)sum/nums.size();// let avg = 1.5 so we need to find 2
        // let increase it 
        avg++;// now find just smaller then it  
        
        unordered_set<int>s(nums.begin(),nums.end());
        if(avg<=0) avg = 1;
        while(1){
            if(s.count(avg)==0) return avg;
            avg++;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n= nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            while(!res.empty()){
                int last = res.back();
                int gc = gcd(last , nums[i]);
                if(gc==1) break;
                res.pop_back();
                int lcm = nums[i]/gc*last;
                nums[i] =(int)lcm;
            }
            res.push_back(nums[i]);
        }
    return res;
    }
};


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        
        vector<bool> res;

        int prod =0;
        for(int bit : nums){
            prod = (prod *2 + bit);
            prod%=5;
            res.push_back(prod==0);
        }
        return res;
        
    }
};
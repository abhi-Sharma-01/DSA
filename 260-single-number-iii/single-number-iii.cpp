class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mapp;
        for(int x:nums){
            mapp[x]++;
        }
        int c=0;
        for(int x:nums){
            if(mapp[x]==1){
                c++;
                res.push_back(x);
                if(c==2) break;
            }
        }
        return res;

    }
};
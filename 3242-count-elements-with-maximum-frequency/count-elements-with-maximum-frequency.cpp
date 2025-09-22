class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mapp;
        int maxF = 0;
        for(int x:nums){
            mapp[x]++;
            maxF = max(maxF,mapp[x]);
        }
        int res =0;
        for(auto [key,val]: mapp){
            if(mapp[key] == maxF){
                res += maxF;
            }
        }
    return res;      
    }
};
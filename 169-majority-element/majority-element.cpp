class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> element;
        for(int i=0;i<n;i++){
            element[nums[i]]++;
        }
        int maxi;
        int limit = n/2 ;
        for(auto i : element){
            int ele = i.first;
            int count = i.second;

            if(count>n/2){
                return ele;
            }
        }
        return -1;
    }
};
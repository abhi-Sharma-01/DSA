class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> element;
        for (int i = 0; i < n; i++) {
            element[nums[i]]++;
        }

        // vector<int> res;
        // int limit = n/3;
        // for(unordered_map<int, int>::iterator i= element.begin();i !=
        // element.end();i++){
        //     int ele = i->first;
        //     int count = i->second;

        //     if(count>limit){
        //         res.push_back(ele);
        //     }
        // }

        // Or

        vector<int> res;
        int limit = n / 3;
        for (auto index : element) {
            int ele = index.first;
            int count = index.second;
            if (count > limit) {
                res.push_back(ele);
            }
        }
        return res;
    }
};
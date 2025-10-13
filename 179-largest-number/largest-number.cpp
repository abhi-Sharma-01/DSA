class Solution {
public:
    static bool compare(string &a, string &b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        int n =  nums.size();
        vector<string> str;
        for(int i=0;i<n;i++){
            string s = to_string(nums[i]);
            str.push_back(s);
        }
        sort(str.begin(),str.end(),compare);
        if (str[0] == "0") return "0";
        string res ="";
        for(auto s: str){
            res += s;
        }
        return res;
    }
};
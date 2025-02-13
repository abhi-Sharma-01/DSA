class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long n = nums.size();
        long long op = 0;
        while (true) { // sort karke phley dono ko hata do ek variable m daal k
            sort(nums.begin(), nums.end());
            if (nums[0] >= k) { // agar smallest ki value >=k then stop just return op
                return op;
            }
            long long newElement = min(nums[0], nums[1]) * 2 + max(nums[0], nums[1]);
            nums.erase(nums.begin());
            nums.erase(nums.begin()); //phley dono remove
            nums.push_back(newElement);
            op++;
            
            
        }
    }
};
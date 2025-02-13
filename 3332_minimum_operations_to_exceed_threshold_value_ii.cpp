//// Approach-1 (Brute Force) i.e sorting again and again and find 2
        //    smallest num to remove
        //     long n = nums.size();
        //     long long op = 0;
        //     while (true) { // sort karke phley dono ko hata do ek variable m
        //     daal k
        //         sort(nums.begin(), nums.end());
        //         if (nums[0] >= k) { // agar smallest ki value >=k then stop
        //         just return op
        //             return op;
        //         }
        //         long long newElement = min(nums[0], nums[1]) * 2 +
        //         max(nums[0], nums[1]); nums.erase(nums.begin());
        //         nums.erase(nums.begin()); //phley dono remove
        //         nums.push_back(newElement);
        //         op++;

        //     }

        // Approach -2 // sort externally and inserting the new element

        // long long op = 0;
        // // Sort initially
        // sort(nums.begin(), nums.end());

        // while (nums.size() >= 2) { // Ensure there are at least 2 elements
        //     if (nums[0] >= k) { // If the smallest element is >= k, return the
        //                         // number of operations
        //         return op;
        //     }

        //     // Convert to long long to prevent overflow
        //     long long x = nums[0];
        //     long long y = nums[1];
        //     long long newElement = x * 2 + y;

        //     // Remove the first two elements
        //     nums.erase(nums.begin());
        //     nums.erase(nums.begin());

        //     // Insert newElement in sorted order to maintain ascending order
        //     nums.insert(upper_bound(nums.begin(), nums.end(), newElement),
        //                 newElement);

        //     op++;
        // }

        // // If there's only one element left, check if it's still < k
        // return op;



        // Approach 3 cheated (as )

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq(begin(nums), end(nums)); //Heapify - log(n)

        int count = 0;

        while(!pq.empty() && pq.top() < k) {
            long smallest = pq.top(); //minimum
            pq.pop();

            long secondSmallest = pq.top(); //max
            pq.pop();

            pq.push(smallest*2 + secondSmallest);

            count++;
        }

        return count;

    }
};
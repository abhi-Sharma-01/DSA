class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {

        long a = 0, maxima = 0, minima = 0;
        for (int d : differences) {
            a += d;
            maxima = max(maxima, a);
            minima = min(minima, a);
        }
        return max(0L,(upper - lower) - (maxima - minima) + 1);
    }
};
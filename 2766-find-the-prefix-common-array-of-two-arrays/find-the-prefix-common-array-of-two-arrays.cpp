class Solution {
public:
    vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> freqA, freqB;
        vector<int> result(n, 0);        
        for (int i = 0; i < n; ++i) {
            freqA[A[i]]++;
            freqB[B[i]]++;            
            int commonCount = 0;
            for (const auto& [num, count] : freqA) {
                if (freqB[num] > 0) {
                    commonCount++;
                }
            }
            result[i] = commonCount;
        }        
        return result;
    }
};

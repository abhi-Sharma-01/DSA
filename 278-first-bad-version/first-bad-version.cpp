// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long low = 1, high = n;
        long long mid, result = n;

        while(low<=high){
            mid = low + (high-low)/2;
            if(isBadVersion(mid)== 1){ /// i.e true
                high = mid -1;
                result = min(mid, result); 
            }else{
                low = mid +1;
            }      
        }
        return result;
    }
};
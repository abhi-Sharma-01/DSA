class Solution {
public:
/*
Constraints:  1 <= low <= high <= 10^4  (10000)
            which Hint us we need to find only for 2-digit(10 - 99) and 4-digit (1000 - 9999)
*/
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for(int n=low;n<=high;++n)  // pre-increment is used as end not included
        {
            if(n<100 && n%11==0){
                res++;
            }else if(n>=1000 && n<10000){
                int leftSum = n/1000 + (n%1000)/100; //to get digit at hundred and Thousand pos.
                int rightSum = (n%100)/10 + n%10;
                if(leftSum == rightSum){
                    res++;
                }
            }
        }
        return res;
    }
};
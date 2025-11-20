class Solution {
public:
    bool isPowerOfFour(int N) {
        unsigned int n = N;
        if(n<=0) return false;
        if(n==1) return true;

        // Should be only 1 set bit 

        if((n & (n-1)) !=0) return false;

        // now we know that we have only one set bit so we can check if its at the odd place
        int pos =0;
        while(n>1){
            n=n>>1;
            pos++;
        }

        return (pos%2==0);
    }
};
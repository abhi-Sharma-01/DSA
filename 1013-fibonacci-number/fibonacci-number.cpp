class Solution {
public:
    int fib(int n) {
        // // M1:
        // if(n<=1) return n;
        // return fib(n-1) + fib(n-2);        

        // M2;
        if(n<=1) return n;
        int fib0 = 0,fib1 =1;
        int fibn =0;
        for(int i=2;i<=n;i++){
            fibn = fib0 + fib1;
            fib0 = fib1;
            fib1 = fibn;
        }
        return fibn;
    }
};
class Solution {
public:
    // string cnvrtToBinary(int n){
    //     if(n == 0) return "0";
    //     string binary = "";
    //     while(n>0){
    //         binary += (n%2==0)? '0':'1';  
    //         n /=2;
    //     }
    //     reverse(binary.begin(),binary.end());   
    //     return binary;
    // }
    bool isPowerOfTwo(int n) {
        // // M-1 Converting n into binary
        // string s = cnvrtToBinary(n);
        // int cnt =0;
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]=='1'){
        //         cnt++;
        //     }
        //     if(cnt>1){
        //         return false;
        //     }
        // }
        // if(cnt !=1) return false;
        // return true;


        // M-2  Directly using STL
        
        if(n <= 0) return false;
        return __builtin_popcount(n) == 1;


    }
};
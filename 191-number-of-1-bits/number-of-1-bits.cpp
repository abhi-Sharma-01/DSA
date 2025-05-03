class Solution {
public:
    string deciTobinary(int n){
        if(n==0) return "0";
        string str = "";
        while(n > 0){
            str += (n % 2 == 0) ? '0' : '1';
            n /= 2;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    int hammingWeight(int n) {
        // // M1- using STL 
        // int cnt = __builtin_popcount(n);
        // return cnt;

        //M2 - without STL
        string s = deciTobinary(n);
        int cnt=0;
        for(int i=0;i<=s.size()-1;i++){
            if(s[i]=='1')
                cnt++;
        }

        return cnt;

    }
};
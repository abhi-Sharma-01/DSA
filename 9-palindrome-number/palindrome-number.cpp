class Solution {
public:
    bool isPalindrome(int x) {

        // Method 1: Using String
        // string str = to_string(x);
        // int n = str.size();
        // for(int i=0;i<n/2;i++){
        //     swap(str[i],str[n-i-1]);
        // }
        // return str == to_string(x);

        // Method 2 two pointer;
        if (x < 0) return false;
        if (x == 0) return true;
        int size = (int)(log10(x)+1);
        int l =0, r =size-1;
        while (l <= r) {
            int leftDigit = (x / (int)pow(10, r)) % 10;
            int rightDigit = (x / (int)pow(10, l)) % 10;

            if (leftDigit != rightDigit) return false;

            l++;
            r--;
        }
        return true;
    }
};
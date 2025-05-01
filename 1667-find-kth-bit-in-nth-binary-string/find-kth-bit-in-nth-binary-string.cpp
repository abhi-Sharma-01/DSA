class Solution {
public:
    string invert(string s){
        for(auto &c:s){  // pass by reference to edit in original string
            c = (c=='0')? '1':'0';
        }
        return s;
    }
    char findKthBit(int n, int k) {  // 1-Based indexed
        string s = "0"; // for i=1
        if(n==1) return '0';
        string toadd ="";
        for(int i=2;i<=n;i++ ){
            string invrt = invert(s);
            reverse(invrt.begin(),invrt.end());
            s = s + "1" + invrt;
        }
        return s[k - 1];  // k is 1-based index, so subtract 1

    }
};
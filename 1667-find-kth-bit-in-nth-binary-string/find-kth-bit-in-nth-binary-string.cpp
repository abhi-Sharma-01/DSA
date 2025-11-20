class Solution {
public:
    string inverse(string s){
        for(auto &c:s){  // pass by reference to edit in original string
            c = ((c-'0') & 1)? '0':'1';
        }
        return s;
    }
    char findKthBit(int n, int k) {  
        string s = "0"; // for i=1
        if(n==1) return '0';
        string toadd ="";
        for(int i=2;i<=n;i++ ){
            string invrt = inverse(s);
            reverse(invrt.begin(),invrt.end());
            s = s + "1" + invrt;
        }
        return s[k - 1];  

    }
};
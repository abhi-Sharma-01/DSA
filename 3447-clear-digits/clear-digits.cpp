class Solution {
public:
    string clearDigits(string s) {
        
        // Approach-1
        int n= s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                s.erase(i,1);
                if(i>0){
                    s.erase(i-1,1);
                    i-=2; // index ko piche karna padega
                    n-=2; //string ka size update
                }else{
                    n--; //
                    i--;
                }
            }
        }
        return s;
        
    }
};
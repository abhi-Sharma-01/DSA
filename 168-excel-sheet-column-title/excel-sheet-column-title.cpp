class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber>0){
            columnNumber--; // converting to 0-based as if(in case 0 we can get char at 64 in ascii code so  needed)
            int digit = columnNumber%26;
            char ch = static_cast<char>(digit+65);  // if Ai.e colNum =1 , colNum-- = 0 therefore ch = A 
            ans += ch;
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
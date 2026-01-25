class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.size();
        string str(n,' ');
        int i=0;
        for(int x:indices){
            str[x] = s[i];
            i++;
        }
        return str;
    }
};
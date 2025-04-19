class Solution {
public:
    string smallestPalindrome(string s) {
        //what i forgot is that given string is already a Palindrome
        int n = s.size();
        if(n==1 || n==2) return s;  // a,aa 
        string f_half = s.substr(0,n/2);//as s is palindrome we can slice it into half
        //now making it the lexigrapically smallest be sorting
        sort(f_half.begin(),f_half.end());
        string s_half = f_half;
        reverse(s_half.begin(),s_half.end());
        if(n%2 == 1) f_half += s[n/2];
        return f_half+s_half;

    }
};
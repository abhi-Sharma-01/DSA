class Solution {
public:
    string countAndSay(int n) {
        string s = "1"; 

        for (int i = 1; i < n; i++) {
            string res = "";
            int count = 1;

            for (int j = 1; j < s.length(); j++) {
                if (s[j] == s[j - 1]) {
                    count++;
                } else {
                    res += to_string(count) + s[j - 1];
                    count = 1;
                }
            }
            res += to_string(count) + s.back();
            s = res; 
        }

        return s;
    }
};
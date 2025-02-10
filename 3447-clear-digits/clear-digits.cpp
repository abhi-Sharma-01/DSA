class Solution {
public:
    string clearDigits(string s) {
        string result = "";
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (!result.empty()) {
                    result.pop_back(); 
                }
            } else {
                result.push_back(s[i]); 
            }
        }
        
        return result;
    }
};

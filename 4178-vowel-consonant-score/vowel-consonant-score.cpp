class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel = 0, conso = 0;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    vowel++;
                else
                    conso++;
            }
        }
        if (conso == 0) return 0;
        return vowel / conso;
    }
};
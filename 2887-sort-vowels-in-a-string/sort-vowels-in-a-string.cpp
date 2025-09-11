class Solution {
public:
    bool isVowel(char ch) {
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' ||  ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
    }
    string sortVowels(string s) {
        int n = s.size();
        vector<int> vowels;
        for (char ch : s) {
            if (isVowel(ch)) vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());
        int idx = 0;
        for (char &ch : s) {
            if (isVowel(ch)) {
                ch = vowels[idx++];
            }
        }
        return s; 
    }
};
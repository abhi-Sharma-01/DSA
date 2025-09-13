class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxFreqSum(string s) {
        int n = s.size();
        if(s.size()==0){
            return 0;
        }
        // agar size> 0
        int maxV =0,maxC =0;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            char ch = s[i];
            freq[ch - 'a']++;  // Update frequency first
            if(isVowel(ch)){
                maxV = max(maxV, freq[ch - 'a']);
            } else {
                maxC = max(maxC, freq[ch - 'a']);
            }

        }
        return maxV+maxC;        
    }
};
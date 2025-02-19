class Solution {
public:
    int firstUniqChar(string s) {
        // Approach -1 // basic Hash map related question
        int n = s.size();
        int hash[26]={0};
        for(char c:s){
            hash[c - 'a']++;
        }
        for(int i=0;i<n;i++){
            if(hash[s[i]-'a'] == 1){
                return i;
            }
        }
        return -1;

    }
};
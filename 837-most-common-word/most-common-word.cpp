class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.size();
        int m = banned.size();

        set<string> banWord(banned.begin(),banned.end());//
        map<string,int> validFreq;

        string word;
        string result;
        int maxCount = 0;

        for(int i=0; i<=n; i++){
            if(isalpha(paragraph[i])){ // checking if the word is alphabet
            word+=tolower(paragraph[i]);
            }else if(!word.empty()){
                if(banWord.find(word)==banWord.end()){
                    validFreq[word]++;
                }
                if(validFreq[word]>maxCount){
                    maxCount=validFreq[word];
                    result = word;
                }
                word="";
            }
        }
        return result;
    }
};
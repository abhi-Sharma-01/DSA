class Solution {
public:
    bool isVowel(char c){
        return c=='a'|| c=='e' || c =='i' || c=='o' || c=='u';
    }
    bool doesAliceWin(string s) {
        // so here we have to count the vowels first 
        int count=0;
        for(char c:s){
            if(isVowel(c)){
                count++;
            }
        }
        // odd vowel hai return true; 
        // count even hua then also 
        // a first mover alice can play a move of count-1 removal then bob pay 0 move and alice wins
        return count>0? true:false;

    }
};
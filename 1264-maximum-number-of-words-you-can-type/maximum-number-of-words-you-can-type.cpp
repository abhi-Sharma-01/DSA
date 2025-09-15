class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters){
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        bool cantype = true;

        for (int i = 0; i <= text.size(); ++i) {
            if (i == text.size() || text[i] == ' ') {
                if (cantype) count++;
                cantype = true; // Reset for next word
            } 
            // else if (broken.count(text[i])) {// one way to find using the count function
            //     cantype = false;
            // }
            // one way to do is using the find() function to do so   i.e 
            else if(broken.find(text[i]) != broken.end()){
                cantype = false;
            }
        }

        return count;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1}); // Now we will use the current word and start making the poosible word by changing the char in it and check if the word exist or not 
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) return step;

            for(int i=0;i<word.size();i++){

                char original = word[i]; //store char if word exist or not after trying all we need to make it as prev

                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]= original;
            }
        }

        return 0;

    }
};
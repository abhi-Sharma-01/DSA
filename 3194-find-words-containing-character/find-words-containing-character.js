/**
 * @param {string[]} words
 * @param {character} x
 * @return {number[]}
 */
var findWordsContaining = function(words, x) {
    const arr = [];
    const n = words.length;
    for(let i=0;i<n;i++){
        if(words[i].includes(x)){
            arr.push(i);
        }
    }
    return arr;
};
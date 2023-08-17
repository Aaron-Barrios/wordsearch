# wordsearch

**Description**
This is a full word search solver in C++. It can find words in an mxn matrix of letters that you provide. Byeond that, you can
- limit the ways words are searched. For example, you can choose for it only to search for words that are written across but not diagonal
- see the places where the words are located, letter by letter
- choose whether you want all the words and their positions printed, or search for a specific word

Currently, the file I'm using to determine if a string of letters is a word or not (words_alpha.txt from https://github.com/dwyl/english-words) includes words that will probably never show up in any word-search- e.g., "aa" and "tgt". I've tried to fix this by making 'words' have two or more letters. As I don't paticularly desire to peruse a nearly 400,000 line text file and subjectively decide which strings of letters aren't word-search material, it will have to do for now. But if there is indeed a better way (or better txt file), please let me know!

**How to run**
Simply enter into the terminal "g++ wordsearch.cpp" to compile, and run it with "./a.out"

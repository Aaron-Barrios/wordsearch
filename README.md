# wordsearch

This is a full word search solver in C++. It can find words in an mxn matrix of letters that you provide, and only in ways that you allow. For example, if you want it to search only for words that are up/down and sideways, it will. This solver can also tell you in what positions are the words at. 

Currently, the remaining bugs are that it:
- Will sometimes tell you the incorrect starting/ending position of words
- Will show words that are only technically words (because the words_alpha.txt from https://github.com/dwyl/english-words includes words that will probably never show up in any word-search ever).

In the future, in addition to fixing these bugs I would also like to add a user menu with options such as _make new wordsearch_, _show all words_ and _find word(s)_. 

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <typeinfo>
using namespace std;


void print_arr(vector<vector<char>> &arr);
string isword(string word, vector<string> wordlist[32]);

int main(){
    
    //Getting all possible words in the enlgish language
    ifstream startFile;
    startFile.open("words_alpha.txt");
    if(!startFile.is_open()){
        cout << "File not open" << endl;
        return 0;
    }

    vector<string> wordlist[32];

    string input = "";
    while(startFile){
        getline(startFile, input);
        wordlist[input.length()-1].push_back(input);
    }
    startFile.close();
    string word = "joke";
    // cout << isword("joke", wordlist) << endl;
    for(int i = 0; i < wordlist[word.length()].size(); i++){
        cout << wordlist[word.length()][i] << endl;
        cout << wordlist[word.length()][i] << "and " << word << endl;
        if(wordlist[word.length()][i] == word){
            cout << "Found it! At " << word.length() << ", " << i << endl;
        }
    }


    // cout << "Hello! Welcome to word search solver." << endl;
    string ans = "";
    // int words_go = 0; //defines way the words go. 
    //0 = none, 1 = forwards, 2 = forwards & diagonal, 3 = forwards, diagonal, & backwards
    // cout << "Can words go any which way? y/n" << endl;
    // cin >> ans;
    // if(ans == "y"){
    //     words_go = 3;
    // }
    // else{
    //     cout << "Can words go straight across? y/n" << endl;
    //     cin >> ans;
    //     if(ans == "y"){
    //         words_go++;
    //     }
    //     cout << "Can words go diagonal? y/n" << endl;
    //     cin >> ans;
    //     if(ans == "y"){
    //         words_go++;
    //     }
    //     cout << "Can words go backwards? y/n" << endl;
    //     cin >> ans;
    //     if(ans == "y"){
    //         words_go++;
    //     }

    // }
    // int m, n = 0;
    
    // // cout << "What are the dimensions of the word search box? E.g. \"4 5\" 4 rows by 5 columns." << endl;
    // // cin >> ans;
    // // n = int(ans[0]);
    // // m = int(ans[ans.length()-1]);
    // n = 3; 
    // m = 3;

    // vector<vector<char>> arrletters(m, vector<char> (n, 0));

    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << "Inputting letter for position " << i << ", " << j << endl;
    //         cin >> ans;
    //         arrletters[i][j] = char(ans[0]);
    //         print_arr(arrletters);
    //     }
    // }
    // // print_arr(arrletters);

    // cout << "Searching for all available words" << endl;

    // string checker = "";
    // string response = "";
    // bool go_way = true; 
    // bool done_wletter = false;
    // bool completed_board = false;
    // int i1 = 0;
    // int j1 = 0;
    // vector<string> found_words;
    // int counter = 0;
    // int type = 0;
    // //starting top left
    // checker = arrletters[i1][j1]; 
    // int column = 0;
    // int row = 0;

    // //moving across

    // while(!completed_board){
    //     while(!done_wletter){ //while we're still on the same letter
    //         while(go_way == true){ //while we haven't found a word this way or reached the end
    //             checker.push_back(arrletters[row][column]);
    //             response = isword(checker, wordlist);
    //             if(response == "" || i1 == m-1 || j1 == n-1){ //check bounds before running
    //                 go_way = false;
    //             }

    //             if(type == 0){ //across
    //                 column = j1 + counter;
    //             }
    //             if(type == 1){ //diagonal
    //                 row = i1 + counter;
    //                 column = j1 + counter;
    //             }
    //             if(type == 2){ //down
    //                 row = i1 + counter;
    //             }
    //             counter++;
    //         }
    //         checker.pop_back(); //make sure it's not empty
    //         if(response != ""){
    //             found_words.push_back(checker);
    //         }
    //         checker = checker[0]; //getting first character again
    //         type++;
    //         if(type == 3){
    //             done_wletter = true;
    //         }
    //     }
    //     completed_board = true;


    //     //ending top right 

    //     //move downwards

    //     //do until at i == m-1, j == n-1
    // }

    // cout << "Here are all the words I could find: " << endl;
    // for(int word = 0; word < found_words.size(); word++){
    //     cout << found_words[word] << endl; //still need to output position
    // }

    return 0;
}

string isword(string word, vector<string> wordlist[32]){
    string thing = "";
    for(int i = 0; i < 32; i++){
        cout << "wordlist[" << i << "] is size " << wordlist[i].size() << endl;
    }

    // for(int i = 0; i < wordlist[4].size(); i++){
    //     thing = wordlist[4][i];

    //     // cout << thing << endl; //", " << word << endl;
    //     if(thing == word){
    //         cout << "got it!" << endl;
    //     }
    // }

    // vector<string> possibles = wordlist[word.length()]; 
    // if(find(possibles.begin(), possibles.end(), word) != possibles.end()){
    //     return word;
    // }
    // cout << word << endl << endl;
    // for(int i = 0; i < possibles.size(); i++){
    //     if(possibles[i][0] == 'j'){
    //         cout << possibles[i] << ": " << word << endl;
    //     }
    //     if(possibles[i] == word){
    //         return word;
    //     }
    // }
    return "";
}

void print_arr(vector<vector<char>> &arr){
    cout << "The letter board is: " << endl << endl;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            if(arr[i][j] == '\0'){
                cout << "- ";
            }
            else{
                cout << arr[i][j] << " ";
            }
            
        }
        cout << endl;
    }
    cout << endl << endl;
}
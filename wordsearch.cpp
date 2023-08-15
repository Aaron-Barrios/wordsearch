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

    cout << "Hello! Welcome to word search solver." << endl;
    bool menuTime = true;
    while(menuTime){
        cout << "Please answer the following questions in order to solve your puzzle. " << endl;
        string ans = "";
        int dirarr[] = {0, 0, 0, 0, 0, 0, 0, 0};
        //A number corresponding to each of the "type" variable's values (0-7)
        cout << "Can words go any which way? y/n" << endl;
        cin >> ans;
        if(ans == "y"){
            for(int k = 0; k < 8; k++){
                dirarr[k] = 1;
            }
        }
        else{
            cout << "Can words go straight across? y/n" << endl;
            cin >> ans;
            if(ans[0] == 'y'){
                dirarr[0] = 1;
            }
            cout << "Can words go down/up? y/n" << endl;
            cin >> ans;
            if(ans[0] == 'y'){
                dirarr[2] = 1;
                dirarr[5] = 1;
            }
            cout << "Can words go diagonal? y/n" << endl;
            cin >> ans;
            if(ans[0] == 'y'){
                dirarr[1] = 1;
                dirarr[6] = 1;
            }
            cout << "Can words go backwards? y/n" << endl;
            cin >> ans;
            if(ans[0] == 'y'){
                dirarr[3] = 1;
                dirarr[4] = 1;
                dirarr[7] = 1;
            }

        }

        int m, n = 0;
        
        cout << "Now for the dimensions of the word search box." << endl;
        cout << "How many rows are there?" << endl;
        ans = "";
        cin >> ans;
        m = stoi(ans); //will make sure this is only one character in length
        cout << "And how many columns?" << endl;
        ans = "";
        cin >> ans;
        n = stoi(ans); //same with this
        

        vector<vector<char>> arrletters(m, vector<char> (n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << "Inputting letter for position " << i << ", " << j << endl;
                cin >> ans;
                arrletters[i][j] = char(ans[0]);
                print_arr(arrletters);
            }
        }
        cout << "Searching for all available words..." << endl << endl;

        string checker = "";
        string response = "";
        string position = "";
        bool go_way = true; 
        bool done_wletter = false;
        bool completed_board = false;
        int i1 = 0;
        int j1 = 0;
        vector<string> found_words;
        vector<string> word_places;
        int counter = 0;
        int type = 0;
        //starting top left
        checker = ""; 
        int column = i1;
        int row = j1;

        //moving across

        while(!completed_board){ //while we've still got letters to check
            
            // cout << endl << "counter3 = " << i1+j1 << endl << endl;
            done_wletter = false;
            type = 0;

            while(!done_wletter){ //while we're still on the same letter

                // cout << endl << "counter2 = " << type << endl << endl;
                checker = ""; //resetting checker
                position = "";
                row = i1;  //reset the rows
                column = j1; //and columns
                counter = 0; //and counter
                go_way = true;
                
                while(go_way == true){ //while we haven't found a word this way or reached the end
                    // cout << endl << "counter = " << counter << endl << endl;
                    if(dirarr[type] == 0){
                        go_way = false;
                        continue;
                    }
                    if(type == 0){ //across (right)
                        // cout << "Checking across" << endl;
                        column = j1 + counter;
                    }
                    if(type == 1){ //diagonal (down-right)
                        // cout << "Checking diagonal" << endl;
                        row = i1 + counter;
                        column = j1 + counter;
                    }
                    if(type == 2){ //down
                        // cout << "Checking down" << endl;
                        row = i1 + counter;
                    }
                    if(type == 3){ //across (left)
                        // cout << "Checking across (backwards)" << endl;
                        column = j1 - counter;
                    }
                    if(type == 4){ //diagonal (up-left)
                        // cout << "Checking diagonal (backwards)" << endl;
                        row = i1 - counter;
                        column = j1 - counter;
                    }
                    if(type == 5){ //up
                        // cout << "Checking up" << endl;
                        row = i1 - counter;
                    }
                    if(type == 6){ //diagonal (up-right)
                        // cout << "Checking across (backwards)" << endl;
                        row = i1 - counter;
                        column = j1 + counter;
                    }
                    if(type == 7){ //diagonal (down-left)
                        // cout << "Checking across (backwards)" << endl;
                        row = i1 + counter;
                        column = j1 - counter;
                    }
                    
                    if(row == m || column == n || row < 0 || column < 0){ //check bounds before running
                        go_way = false;
                        continue;
                    }
                    checker.push_back(arrletters[row][column]);
                    position += "->(" + to_string(row) + ", " + to_string(column) + ")";
                    // position.push_back(to_string(row)[0]);
                    // position.push_back(',');
                    // cout << "i1 = " << i1 << ", j1 = " << j1 << endl;
                    // cout << "checker: " << checker << endl;
                    if(counter == 0){
                        counter++;
                        continue; //maybe the right keyword
                    }
                    response = isword(checker, wordlist); 
                    //if we're not out of bounds or first iteration, let's see if we've got a word
                    if(response != "" && response.length() > 2){ //if it is a word, let's append it (and it's longer than 2 letters)
                        auto place = find(found_words.begin(), found_words.end(), response);
                        if(place != found_words.end()){
                            found_words[place - found_words.begin()] = "nothere";
                            word_places[place - found_words.begin()] = "nothere";
                        }
                        found_words.push_back(response);
                        word_places.push_back(position);
                        //also need to remove words that aren't really words
                    }
                    counter++;
                }

                //found a word or reached the end of this way
                type++; //move onto the next type of searching
                if(type == 8){ //if we've searched all the ways, then let's exit this loop
                    done_wletter = true;
                }
            }
            
            //how do I go to the next letter?
            j1++; //if we're still moving right
            if(j1 == n){
                j1 = 0;
                i1++;
                if(i1 == m){
                    completed_board = true;
                }
            }
        }
        bool smalloop = true;
        while(smalloop){
            cout << "Would you like to look for a specific word, or print all of them out at once? 1/2" << endl;
            ans = "";
            cin >> ans;
            if(ans[0] == '1'){
                cout << "What is the word you would like to search for?" << endl;
                cin >> ans;
                auto place = find(found_words.begin(), found_words.end(), ans);
                if(place == found_words.end()){
                    cout << "Sorry, couldn't find it." << endl;
                }
                else{
                    cout << found_words[place - found_words.begin()] << " at (row, column) = ";
                    cout << word_places[place - found_words.begin()] << endl;
                }
            }
            if(ans[0] == '2'){
                cout << "Here are all the words I could find: " << endl;
                for(int word = 0; word < found_words.size(); word++){
                    if(found_words[word] != "nothere"){
                        cout << found_words[word] << " at (row, column) = " << word_places[word] << endl;
                    }
                }
            }
            cout << "Do you want to search for a new word/print them all out (1),";
            cout << "start a new word search (2), or quit (3)?" << endl;
            cin >> ans;
            if(ans[0] == '2'){
                smalloop = false;
            }
            if(ans[0] == '3'){
                smalloop = false;
                menuTime = false;
            }
        }
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}

string isword(string word, vector<string> wordlist[32]){
    
    string thing = "";
    //for some reason, it will only work if I check character by character, 
    //instead of one string at once. 
    for(int i = 0; i < wordlist[word.size()].size(); i++){ 
        bool isit = true;
        thing = wordlist[word.size()][i];
        for(int j = 0; j < word.length(); j++){
            if(thing[j] != word[j]){
               isit = false;
            }
        }
        if(isit == true){
            // cout << "Got it!" << endl;
            return word;
        }
    }
    // cout << "Didn't find it" << endl;
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

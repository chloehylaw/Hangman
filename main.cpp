#include <iostream>
#include <algorithm>
#include<ctime>

using namespace std;
const int MAX_TRIES = 10;
int letterFill(char, string, string&);
void myWord();
void yourWord(string);
int main() {
    cout << "Let's play hangman!\n1. Guess my word!\n2. Guess your word!\n3. Let's play another time!\nWhat is your choice?" << endl;
    cout << ">>";
    int num;
    string word;
    cin >> num;
    switch(num){
        case 1:
            cout << "\nLet me choose a word...\nGot it!";
            myWord();
            break;
        case 2:
            cout << "\nEnter your secret word right here:\n>>";
            cin >> word;
            yourWord(word);
            break;
        case 3:
            cout << "\nWe will have more opportunities to play another time!\nBye!";
            break;
        default:
            cout << "\nYou have entered something weird...\nWe will play another time!\nBye!";
    }

    cin.ignore();
    cin.get();
    return 0;
}

void myWord(){
    string words[] = {
            "apple", "pineapple", "banana", "orange", "grapefruit", "watermelon", "cantaloupe", "strawberries", "lychee", "mango"
    };
    srand(time(NULL));
    int n=rand()% 10;
    string word;
    word=words[n];
    string unknown(word.length(),'*');
    int numGuess = 0;
    char letter;
    cout << "Each letter is covered by a star.\nYou have " << MAX_TRIES << " tries to guess my word!\nHere is a hint: fruit.\n";
    while(numGuess < MAX_TRIES){
        cout << unknown << "\n\n";
        cout << "You picked\n>>";
        cin >> letter;
        if(letterFill(letter, word, unknown) == 0){
            cout << endl << "You didn't guess it right!" << endl;
            numGuess++;
        }else{
            cout << endl << "Finally, You found a letter!" << endl;
        }
        cout << "You have " << MAX_TRIES - numGuess << " guesses left." << endl;
        if(word == unknown){
            cout << word << endl;
            cout << "You finally got my secret word!";
            break;
        }
    }
    if(numGuess == MAX_TRIES) {
        cout << "\nDammit! I have lost all of my chances...\nI have been hanged."
                "\n\nLet me see what your word was...\nIt was " << word << endl;
    }
}

void yourWord(string word){
    string unknown(word.length(), '*');
    int numGuess = 0;
    char letter;
    cout << "Each letter is covered by a star.\nI have " << MAX_TRIES << " tries to guess your word!";
    while(numGuess < MAX_TRIES){
        cout << unknown << "\n\n";
        letter = 'a' + rand()%26;
        cout << "I pick " << letter << ".";
        if(letterFill(letter, word, unknown) == 0){
            cout << endl << "I didn't guess it right!" << endl;
            numGuess++;
        }else{
            cout << endl << "Finally, I found a letter!" << endl;
        }
        cout << "I have " << MAX_TRIES - numGuess << " guesses left." << endl;
        if(word == unknown){
            cout << word << endl;
            cout << "I finally got your secret word!";
            break;
        }
    }
    if(numGuess == MAX_TRIES) {
        cout << "\nDammit! I have lost all of my chances...\nI have been hanged."
                "\n\nLet me see what your word was...\nIt was " << word << endl;
    }
}
int letterFill(char guess, string word, string &guessword){
    int matches = 0;
    for(int i = 0; i < word.length(); i++){
        if(guess == guessword[i]){
            return 0;
        }
        if(guess == word[i]){
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

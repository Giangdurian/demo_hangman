#include<bits/stdc++.h>
using namespace std;
const int MAX_BAD_GUESSED = 7;


void update(string& guessedWord,const string& secretWord, char guess){
    for(int i = 0; i < secretWord.length(); i++){
        if(secretWord[i] == guess){
            guessedWord[i] = guess;
        }
    }
}

bool contains(string secretWord, char guess){
    if(secretWord.find_first_of(guess) != string::npos)  return true;
    return false;
}

const string WORD_LIST[] = {"hoaancut"};
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);

string chooseWord(){
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
}

const string FIGURE[]{
    " -------------     \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |                 \n"
    " |                 \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |           |     \n"
    " |                 \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|     \n"
    " |                 \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |                 \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |          /      \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |          / \\   \n"
    " |                 \n"
    " -----             \n",
};


void renderGame(string guessedWord, int badGuessCount){
    cout << FIGURE[badGuessCount] << endl;
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}

int main(){
    srand(time(0));
    int badGuessCount = 0;
    string secretWord = chooseWord();
    string guessedWord(secretWord.length(), '-');
    cout << guessedWord << endl;
    char guess;
    do{ 
        renderGame(guessedWord,badGuessCount);
        cout << "Enter your guess: ";
        cin >> guess;
        guess = tolower(guess);
        if(contains(secretWord, guess)){
            update(guessedWord, secretWord, guess);
        }else{
            badGuessCount++;
        }
    }while(badGuessCount < MAX_BAD_GUESSED && secretWord != guessedWord);
    if (badGuessCount < 7) cout << "Congratulations! You win!";
    else cout << "You lost. The correct word is " << secretWord;
}
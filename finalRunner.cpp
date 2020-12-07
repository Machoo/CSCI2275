#include <iostream>
#include <vector>
#include "Game.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    /*
        Welcome to Hangman!
        There are four starting configurations that you can choose:
        1. Leave this file as it is; the game will allow 26 turns and will choose a random word
        2. Add an additional argument to the definition of dict below that is an integer,
           this will limit how many words are read from the dictionary.txt file
           (use this if that reading is taking a while)
           Range: 10-10000 (any higher values would be meaningless)
        3. The same as 2, except the integer defines the max number of turns,
           and add a third boolean argument that is just true
           Range: 3-26
        4. A combination of 2 and 3: define the number of words to be read in argument 2,
           and the max turns in argument 3

        To play the game, select one to guess a letter
        If the hidden word (shown by the asterisks) contains that letter,
        the turn counter doesn't increment and the hidden word will be updated
        Try to guess the word!
    */
    Dictionary dict(argv[1], 6, true);
    Game g;
    g.turn(dict);
}
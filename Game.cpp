#include <string>
#include <iostream>
#include "Game.h"

using namespace std;

LL::LL() {
    head = NULL;
}

void LL::append(char value) {
    LLNode* node = new LLNode;
    node->val = value;
    if (head == NULL) {
        head = node;
    } else {
        LLNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void LL::showLL() {
    cout << "Letters guessed: ";
    if (head == NULL) {
        cout << "None"; 
    }
    LLNode *crawler = head;
    while(crawler != NULL) {
        cout << crawler->val;
        if (crawler->next != NULL)
            cout << ", ";
        crawler = crawler->next;
    }
    cout << "\n";
}

Game::Game() {
    cout << "game initialized\n";
}

void Game::turn(Dictionary dict) {
    LL guessed;
    dict.getRandomWord();
    cout << dict.getWord() << "\n";
    bool playing = true;
    int turn;
    bool good = false;
    while (playing) {
        if (turn > dict.maxTurns) {
            cout << "Game Over!\nThe word was " << dict.getWord() << "\n";
            break;
        } else if (dict.wordSoFar == dict.getWord()) {
            cout << "Congratulations!\n";
            break;
        }
        turn = dict.drawScreen();
        if (good) {
            cout << "That letter was not in the word\n";
            good = false;
        }
        cout << "-Hangman-\n ____\n/    |\n|    O\n|   /|\\ \n|    |\n|   / \\ \n|\n|_______\n" << "Turn: " << turn << " / " << dict.maxTurns << "\n" << dict.wordSoFar << "\n";
        guessed.showLL();
        cout << "Guess a letter: 1  Search for a word: 2  Concede: 3\n";
        int input;
        cin >> input;
        char inp;
        string inpW;
        bool found;
        char endy;
        switch (input) {
            case 1: {
                cout << "Letter: ";
                cin >> inp;
                guessed.append(inp);
                good = (!(dict.submitLetter(inp)));
                break;
            }
            case 2: {
                cout << "Word: ";
                cin >> inpW;
                found = dict.search(inpW);
                if (found) {
                    cout << inpW << " exists in the dictionary\n";
                } else {
                    cout << inpW << " is not a viable word\n";
                }
                break;
            }
            case 3: {
                cout << "Are you sure? The final word will be shown. y/n\n";
                cin >> endy;
                if (endy == 'y') {
                    playing = false;
                }
                cout << dict.getWord() << "\n";
                break;
            }
        }
    }
}

/*
 ____
/    |
|    O
|   /|\
|    |
|   / \
|
|_______



*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include "Dictionary.h"

using namespace std;

bool Dictionary::readDictFile(string fileName) {
    ifstream fileIn;
    fileIn.open(fileName);
    if (fileIn.is_open()) {
        string word;
        while (getline(fileIn, word)) {
            storeWord(word);
        }
    }
    fileIn.close();
    return false;
}

bool Dictionary::readDictFile(string fileName, int maxWords) {
    ifstream fileIn;
    fileIn.open(fileName);
    if (fileIn.is_open()) {
        string word;
        int counter = 0;
        while (getline(fileIn, word) && counter < maxWords) {
            storeWord(word);
            counter++;
        }
    }
    fileIn.close();
    return false;
}

bool Dictionary::storeWord(string word) {
    words.at(word.length()).push_back(word);
    return true;
}

bool Dictionary::checkForLetter(char letter) {
    bool letterThere = (chosenWord.find(letter) != -1);
    if (letterThere) {
        for (int i = 0; i < wordSoFar.length(); i++) {
            if (chosenWord[i] == letter) {
                wordSoFar[i] = letter;
            }
        }
        turnsMade--; //make maxTurns public, show x/y for turns, implement actual turn limit
    }
    return letterThere;
}

int Dictionary::drawScreen() {
    for (int i = 0; i < 50; i++) {
        cout << "\n";
    }
    return turnsMade;
}

Dictionary::Dictionary(string fileName) {
    for (int i = 0; i < 19; i++) {
        vector<string> temp;
        words.push_back(temp);
    }
    readDictFile(fileName);
    maxTurns = 26;
    turnsMade = 1;
}

Dictionary::Dictionary(string fileName, int word) {
    for (int i = 0; i < 19; i++) {
        vector<string> temp;
        words.push_back(temp);
    }
    readDictFile(fileName, word);
    maxTurns = 26;
    turnsMade = 1;
}

Dictionary::Dictionary(string fileName, int maxTurn, bool turnsNotWords) {
    for (int i = 0; i < 19; i++) {
        vector<string> temp;
        words.push_back(temp);
    }
    readDictFile(fileName);
    maxTurns = maxTurn;
    turnsMade = 1;
}

Dictionary::Dictionary(string fileName, int word, int maxTurn) {
    for (int i = 0; i < 19; i++) {
        vector<string> temp;
        words.push_back(temp);
    }
    readDictFile(fileName, word);
    maxTurns = maxTurn;
    turnsMade = 1;
}

bool Dictionary::search(string word) {
    vector<string> temp = words.at(word.length());
    for (int i = 0; i < temp.size(); i++) {
        if (temp.at(i) == word) {
            return true;
        }
    }
    return false;
}

bool Dictionary::submitLetter(char letter) {
    turnsMade++;
    return checkForLetter(letter);
}

string Dictionary::getWord() {
    return chosenWord;
}

void Dictionary::printDict() {
    for (int i = 0; i < words.size(); i++) {
        cout << (i + 1) << ": ";
        for (int j = 0; j < words.at(i).size(); j++) {
            cout << words.at(i).at(j) << ", ";
        }
        cout << "\n";
    }
}

string Dictionary::getRandomWord() { //occasionally returns nothing; bug with time?
    srand(time(0));
    int randy = rand() % 15 + 3;
    while (words.at(randy).empty()) {
        randy = rand() % 15 + 3;
    }
    int randtwo = rand() % (words.at(randy).size());
    chosenWord = words.at(randy).at(randtwo);
    wordSoFar = string(chosenWord.length(), '*');
    return chosenWord;
}

string Dictionary::getRandomWord(int length) {
    srand(time(0));
    if (words.at(length).empty()) {
        return "empty";
    }
    int randtwo = rand() % (words.at(length).size());
    chosenWord = words.at(length).at(randtwo);
    wordSoFar = string(chosenWord.length(), '*');
    return chosenWord;
}

string Dictionary::findMostUniqueWords(int numWords) {

    return "-1";
}

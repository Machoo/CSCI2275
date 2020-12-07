#include <string>
#include <vector>

using namespace std;

class Dictionary {
    private:
        vector<vector<string>> words;
        int turnsMade;
        string chosenWord;
        bool readDictFile(string fileName);
        bool readDictFile(string fileName, int maxWords);
        bool storeWord(string word);
        bool checkForLetter(char letter);
    public:
        int maxTurns;
        string wordSoFar;
        Dictionary(string fileName);
        Dictionary(string fileName, int word);
        Dictionary(string fileName, int maxTurn, bool turnsNotWords);
        Dictionary(string fileName, int word, int maxTurn);
        int drawScreen();
        bool search(string word); //to check if something is a viable word, easily
        bool submitLetter(char letter);
        string getWord();
        void printDict();
        string getRandomWord();
        string getRandomWord(int length);
        string findMostUniqueWords(int numWords);
};
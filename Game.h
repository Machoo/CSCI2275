#include <string>
#include "Dictionary.h"

using namespace std;

struct LLNode {
    char val;
    LLNode *next = NULL;
};

class LL {
    private:
        LLNode *head;
    public:
        LL();
        void append(char val);
        void showLL();
};

class Game {
    public:
        Game();
        void turn(Dictionary dict);
};
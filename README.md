# CSCI2275
Project Summary:
This project is a text-based implementation of the game Hangman. The objective of the game is to guess a word given the number of letters in it and a set number of guesses of letters. A correct guess does not cost a turn and will reveal all instances of that letter in the hidden word. The words are chosen from the 10000 most-used English words, although they can also be abbreviations (such as "lol"). If all of the turns are used (which is indicated by the turn counter being larger than the max number of turns, not equal to them), the game is over and the word is revealed. If the word is completely revealed, you win! Another option is, in case you're skeptical, to check which words exist in the dictionary (because there are definitely ommitted words).

How To Run:
After compiling finalRunner.cpp, execute the .exe file with a command line argument of the dictionary source word .txt file. By default this is dictionary.txt, but if you wish to provide another library ensure that each word is on a new line. The game does not restart upon completion; you must execute the compiled file to play it again.

Dependencies:
This program requires no internet connection to run and will perform normally so long as all of the files it requires (Dictionary, Game, and dictionary.txt) are in the same folder as it.

System Requirements:
One aspect of the game is random number generation to select a random word. In order to achieve this, the computer's time is used as an activation key to generate truly random numbers. While this is guaranteed to work on Windows 10 systems, it is safe to assume it would also work on all other modern operating systems.

Team Members:
Matthew Kind

Contributors:
Although nobody else directly contributed to this project, I'd like to cite this Github repository for providing the word library (https://github.com/first20hours/google-10000-english).

Open Issues/Bugs:
When initially developing this project, a random word would occasionally not be generated, and would end the program early. In the last 30 or so tests, this has not occured. I feel the need to mention it because the problem dissappeared without my direct intervention, and may still occur (but fairly infrequently).
As well, the hanging man graphic does not update, mostly on account of there not being a reasonable way to store 25 different configurations of the character being drawn per turn. I may yet find a solution with a set number of "drawing updates", but the feature is purely aesthetic.

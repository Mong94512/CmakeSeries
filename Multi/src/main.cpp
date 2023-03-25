#include "function.h"

int main()
{   
    bool running = true;  
    instruction();

    do{
        char spaces[] = {' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char fragments[] = {'O', '|', '/', '\\', '|', '/', '\\'};
        std::string codeWordOption[] = {"AZUTHEVOLCANICERUPTIONCHINKBENGAY", "FATGEORGEWHENISEEGEORGE", "DELAYTHEDEGAY", 
                                        "EMEMBENLADEN", "AUVEEPEEPISS", "CANABONK", "COCONOMIKAPERCYYATIMAENJOYER",
                                        "TAXICALBENTESTICAL"};
        int deathCount = 0;
        std::string codeWord;
        char guess;
        std::string answer;
        std::vector<char> usedLetter;
        bool guessedWord = false, reuse = false, guessing = true;

        codeWordRoll(codeWordOption, codeWord, answer);
        gameBoard(spaces, deathCount, answer, usedLetter);

        while(answer != codeWord && deathCount < 8){
            playerGuess(guessing, guess, usedLetter, reuse);
            verifyingGuess(codeWord, answer, guessedWord, guess);
            printGuessResult(guessedWord, spaces, fragments, deathCount, usedLetter, guess);
            gameBoard(spaces, deathCount, answer, usedLetter);
        }
        endGame(answer, codeWord);
        retry(running);
    }while(running == true);
    
    return 0;
}
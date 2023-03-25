#include "function.h"

void instruction(){
    std::cout<<"********||THE HANGMAN GAME||************\n\n";
    std::cout<<"************INSTRUCTION******************\n";
    std::cout<<"1.Help George from being executed by guessing the correct codeword.\n";
    std::cout<<"2.Codeword are guessed by per letter.\n";
    std::cout<<"3.Used word can't be reuse.\n";  
    std::cout<<"4.Deathcount will increase by one each time you guess the letter wrong.\n";
    std::cout<<"5.Fail to guess the correct Codeword within 7 tries will result in game over.\n";
    std::cout<<"6.Codeword hint: SADCAT MEMBER NAME\n";
    std::cout<<"\nPRESS ANY KEY TO START THE GAME...........\n";    
}

void gameBoard(char spaces[], int &deathCount, std::string &answer, std::vector<char> &usedLetter){
    std::cout<<"+___________________________________+\n";
    std::cout<<"|         PLEASE SAVE GEORGE!       |\n";
    std::cout<<"| HE IS TOO FAT, IT WON'T LAST LONG!|\n";
    std::cout<<"|___________________________________|\n";
    std::cout<<"             +====+\n";
    std::cout<<"             |    |\n";
    std::cout<<"             "<<spaces[0]<<"    |\n";
    std::cout<<"            "<<spaces[2]<<spaces[1]<<spaces[3]<<"   |\n";
    std::cout<<"             "<<spaces[4]<<"    |\n";
    std::cout<<"            "<<spaces[5]<<" "<<spaces[6]<<"   |\n";
    std::cout<<"                  |\n";
    std::cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n";
    std::cout<<"MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW\n";
    std::cout<<"-------------------------------------\n\n";
    std::cout<<"Death count: "<<deathCount<<'\n';
    std::cout<<"Used letters: ";
    for(int i=0; i<usedLetter.size(); i++){
        std::cout<<usedLetter[i]<<" ";
    }
    std::cout<<"\nCodeWord: ";
    for(int i=0; i<answer.length(); i++){
        std::cout<<answer[i]<<" ";
    }

}

void codeWordRoll(std::string codeWordOption[], std::string &codeWord, std::string &answer){
    int roll;
    srand(time(0));
    roll = rand()%5;
    switch(roll){
        case 0: codeWord = codeWordOption[0];
                break;
        case 1: codeWord = codeWordOption[1];
                break;
        case 2: codeWord = codeWordOption[2];
                break;
        case 3: codeWord = codeWordOption[3];
                break;
        case 4: codeWord = codeWordOption[4];
                break;
    }
    answer = codeWord;
    for(int i=0; i<answer.length(); i++){
        answer[i] = '_';
    }
}

void playerGuess(bool &guessing, char &guess, std::vector<char> &usedLetter, bool &reuse){
    while(guessing){
        std::cout<<"\nEnter guess: ";
        std::cin>>guess;
        guess = toupper(guess);
        for(int i=0; i<usedLetter.size(); i++){
            if(guess == usedLetter[i]){
                std::cout<<"Letter had been used.";
                reuse = true;
                break;
            }
        }
        if(reuse == false){
            break;
        }
        reuse = false;
    }
}

void verifyingGuess(std::string &codeWord, std::string &answer, bool &guessedWord, char &guess){
    for(int i=0; i<codeWord.length(); i++){
        if(guess == codeWord[i]){
            answer[i] = codeWord[i];
            guessedWord = true;
        }
    }
}

void printGuessResult(bool &guessedWord, char spaces[], char fragments[], int &deathCount, std::vector<char> &usedLetter, char &guess){
    if(guessedWord == true){
            std::cout<<"Good start king!\n";
        }
    if(guessedWord == false){
        std::cout<<"Wrong guess dumbass! Another fragment of George had been drawn.\n";
        spaces[deathCount] = fragments[deathCount];
        deathCount++;
    }
    usedLetter.push_back(guess);
    guessedWord = false;
}

void endGame(std::string &answer, std::string &codeWord){
    if(answer == codeWord){
        std::cout<<"\nPhew, you made it. George saved!\n";
    }
    else{
        std::cout<<"\nGeorge had been slain\n";
    }
}

void retry(bool &running){
    int choice;
    std::cout<<"1.Retry   2.Exit\n";
    std::cin>>choice;
    switch(choice){
        case 1: break;
        case 2: running = false;
                break;
    }
}

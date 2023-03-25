#ifndef FUNCTION_H
#define FUNCTION_H

#include<iostream>
#include<vector>
#include<ctime>
#include<cctype>

void instruction();
void gameBoard(char spaces[], int &deathCount, std::string &answer, std::vector<char> &usedLetter);
void codeWordRoll(std::string codeWordOption[], std::string &codeWord, std::string &answer);
void playerGuess(bool &guessing, char &guess, std::vector<char> &usedLetter, bool &reuse);
void verifyingGuess(std::string &codeWord, std::string &answer, bool &guessedWord, char &guess);
void printGuessResult(bool &guessedWord, char spaces[], char fragments[], int &deathCount, std::vector<char> &usedLetter, char &guess);
void endGame(std::string &answer, std::string &codeWord);
void retry(bool &running);

#endif
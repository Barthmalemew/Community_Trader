#pragma once

constexpr int MAXSIZE = 10;
constexpr int NAMESIZE = 11;
constexpr int REQUESTSIZE = 25;

void userInput(bool arrayS[], char arrayN[][NAMESIZE], char arrayR[][REQUESTSIZE], int INDEX);

void userOutput(const bool arrayS[], const char arrayN[][NAMESIZE], const char arrayR[][REQUESTSIZE], int INDEX, int uId);

void userGive(bool arrayS[], const char arrayN[][NAMESIZE], const char arrayR[][REQUESTSIZE], int ID);

void randInnit(bool arrayS[], int MAXSIZE);

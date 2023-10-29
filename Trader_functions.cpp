#include "Trader_functions.h"
#include <iostream>
#include <cctype>
#include<cstdlib>
#include<ctime>

using namespace std;


void userInput(bool arrayS[], char arrayN[][NAMESIZE], char arrayR[][REQUESTSIZE], int INDEX)
{
	char decision;
	bool reqCheck = false;

	cout << "Enter your name: ";
	cin.getline(arrayN[INDEX], NAMESIZE);

	cout << "User do you want to make a request? Enter y/n: ";
	decision = cin.get();
	cin.ignore(256, '\n');
	decision = tolower(decision);


	if (decision == 'y')
	{
		reqCheck = true;
	}
	else if (decision == 'n')
	{
		reqCheck = false;
	}


	// checks if user has already made a request and if they are currently making a request
	if (arrayS[INDEX] == false && reqCheck == true)
	{

		cout << "What request do you want to make?: ";
		cin.getline(arrayR[INDEX], REQUESTSIZE);
		arrayS[INDEX] = reqCheck;
	}
	else if (arrayS[INDEX] == true && reqCheck == true)
	{
		cout << "User already has one pending request." << endl;
	}
	else
	{
		cout << "Have a good day!" << endl;
	}
}


void userOutput(const bool arrayS[], const char arrayN[][NAMESIZE], const char arrayR[][REQUESTSIZE], int INDEX, int uId)
{
	if (arrayS[INDEX] == true && INDEX != uId)
	{
		cout << INDEX << " ";
		cout << arrayN[INDEX] << " ";
		cout << arrayR[INDEX] << endl;
	}
}

void userGive(bool arrayS[], const char arrayN[][NAMESIZE], const char arrayR[][REQUESTSIZE], int uId)
{
	char decision;
	int targetIndex;
	int rId = 0; //index of the person the user is fulfilling the request of

	do
	{
		decision = ' ';
		targetIndex = 0;
		bool reciveGive = false;
		cout << "Enter an index of a person whose request you want to fulfill or -1 to exit the program: "; //remeber to tell the user the exit value 
		cin >> targetIndex;

		if (targetIndex != -1 && (arrayS[targetIndex] == true && targetIndex < MAXSIZE && targetIndex != uId)) //will be a do while
		{
			cout << "Enter y to confirm filling the order, and n to cancel and go back to selecting: ";
			cin >> decision;
			decision = tolower(decision);

			if (decision == 'y')
			{
				arrayS[targetIndex] = false;
				reciveGive = bool(rand() > (RAND_MAX / 2));
				if (reciveGive == true && arrayS[uId] == true)
				{
					arrayS[uId] = false;
					cout << "Anonymous has fulfilled your request as thanks\n";

				}
				else
				{
					cout << "Anonymous has thanked you for fulfilling their request \n";
				}

			}
			else if (decision == 'n')
			{

			}
		}
		else if (targetIndex != -1)
		{
			cout << "Invalid index, please try again.\n";
		}
	} while (targetIndex != -1);





}

void randInnit(bool arrayS[], int MAXSIZE)
{

	for (int i = 0; i < MAXSIZE; i++)
	{
		arrayS[i] = bool(rand() > (RAND_MAX / 2));
	}
}
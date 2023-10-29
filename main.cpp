#include <iostream>
#include <cctype>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

const int MAXSIZE = 10;
const int NAMESIZE = 11;
const int REQUESTSIZE = 25;

void userInput(bool arrayS[],char arrayN[][NAMESIZE],char arrayR[][REQUESTSIZE], int INDEX);

void userOutput(const bool arrayS[],const char arrayN[][NAMESIZE],const char arrayR[][REQUESTSIZE], int INDEX, int uId);

void userGive(bool arrayS[], const char arrayN[][NAMESIZE], const char arrayR[][REQUESTSIZE], int ID);

void randInnit(bool arrayS[], int MAXSIZE);


int main()
{
	bool requestArray[MAXSIZE];
	char nameBox[MAXSIZE][NAMESIZE];
	char requestBox[MAXSIZE][REQUESTSIZE];

	srand(time(0));

	int userId = 7;
	int userIdInput = 0;
	int pin = 4963;
	int pinInput = 0;

	//intitalizing every index with values sans the users index // We have to shorten this 
   
	randInnit(requestArray, MAXSIZE);

	snprintf(nameBox[0], NAMESIZE, "John");
	snprintf(nameBox[1], NAMESIZE, "Alex");
	snprintf(nameBox[2], NAMESIZE, "Zoe");
	snprintf(nameBox[3], NAMESIZE, "Bob");
	snprintf(nameBox[4], NAMESIZE, "Cindy");
	snprintf(nameBox[5], NAMESIZE, "Sera");
	snprintf(nameBox[6], NAMESIZE, "Tom");
	snprintf(nameBox[8], NAMESIZE, "Kat");
	snprintf(nameBox[9], NAMESIZE, "Belle");

	snprintf(requestBox[0], REQUESTSIZE, "%d Burger[s]",(rand() % 50 +1));
	snprintf(requestBox[1], REQUESTSIZE, "%d Laptop[s]",(rand() % 50 + 1));
	snprintf(requestBox[2], REQUESTSIZE, "%d Hairbrushs", (rand() % 50 + 1));
	snprintf(requestBox[3], REQUESTSIZE, "%d Bricks",(rand() % 50 + 1));
	snprintf(requestBox[4], REQUESTSIZE, "%d Books", (rand() % 50 + 1));
	snprintf(requestBox[5], REQUESTSIZE, "%d Cats",(rand() % 50 +1));
	snprintf(requestBox[6], REQUESTSIZE, "%d Fish", (rand() % 50 + 1));
	snprintf(requestBox[8], REQUESTSIZE, "%d Knives", (rand() % 50 + 1));
	snprintf(requestBox[9], REQUESTSIZE, "%d Golden Bells", (rand() % 50 + 1));

 ;
 cout << "-------------------------------\n";
	cout << "Enter User ID: ";
	cin >> userIdInput;
	cin.ignore(256, '\n');
	if (userIdInput == userId)
	{
		cout << "Enter Passcode: ";
		cin >> pinInput;
		cin.ignore(256, '\n');
		if (pinInput == pin)
		{
			printf("Welcome User %d \n", userId);
		}
	}
	cout << "-------------------------------\n";



	userInput(requestArray, nameBox, requestBox, userId);

	cout << "-------------------------------\n";

	for(int i = 0; i < MAXSIZE; i++ )
	{
	   userOutput(requestArray, nameBox, requestBox, i, userId);
	}
	cout << "-------------------------------\n";

	userGive(requestArray, nameBox, requestBox, userId);

}

void userInput(bool arrayS[],char arrayN[][NAMESIZE],char arrayR[][REQUESTSIZE], int INDEX)
{
	char decision;
	bool reqCheck = false;

	cout << "Enter your name: ";
	cin.getline(arrayN[INDEX], NAMESIZE);

	cout << "User do you want to make a request? Enter y/n: ";
	decision = cin.get();
	cin.ignore(256, '\n' );
	decision = tolower(decision);
	
   
	if(decision == 'y')
	{
		reqCheck = true;
	}
	else if(decision == 'n')
	{
		reqCheck = false;
	}
	
	
	// checks if user has already made a request and if they are currently making a request
	if(arrayS[INDEX] == false && reqCheck == true)
	{
	   
	   cout << "What request do you want to make?: ";
	   cin.getline(arrayR[INDEX], REQUESTSIZE);
	   arrayS[INDEX] = reqCheck; 
	}
	else if(arrayS[INDEX] == true && reqCheck == true)
	{
		cout << "User already has one pending request." << endl;
	}
	else
	{
		cout << "Have a good day!" << endl; 
	}
}


void userOutput(const bool arrayS[],const char arrayN[][NAMESIZE],const char arrayR[][REQUESTSIZE], int INDEX, int uId)
{
	if(arrayS[INDEX] == true && INDEX != uId)
	{
		/*
		cout << "|" << INDEX << " ";
		cout << arrayN[INDEX] << " ";
		cout << arrayR[INDEX] << "*" << endl;
		*/

		printf("| %d %-6s %-18s | \n",INDEX, arrayN[INDEX], arrayR[INDEX]);
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
					cout << "ASCII cat goes here";
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
		if (i == 7)
		{
			arrayS[i] = false;
		}
		else
		{
			arrayS[i] = bool(rand() > (RAND_MAX / 2));
		}
	}
}


#include <iostream>
#include <cctype>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include "Trader_functions.h"

using namespace std;





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
				  



	userInput(requestArray, nameBox, requestBox, userId);

	for(int i = 0; i < MAXSIZE; i++ )
	{
	   userOutput(requestArray, nameBox, requestBox, i, userId);
	}
	userGive(requestArray, nameBox, requestBox, userId);

}




#include <iostream>
#include <cctype>

using namespace std;

const int MAXSIZE = 10;
const int NAMESIZE = 11;
const int REQUESTSIZE = 25;


void userInput(bool arrayS[],char arrayN[][NAMESIZE],char arrayR[][REQUESTSIZE], int INDEX);

void userOutput(const bool arrayS[],const char arrayN[][NAMESIZE],const char arrayR[][REQUESTSIZE], int INDEX);

int main()
{
    bool requestArray[MAXSIZE];
    char nameBox[MAXSIZE][NAMESIZE];
    char requestBox[MAXSIZE][REQUESTSIZE];

    int userId = 7;
    int userIdInput = 0;
    int pin = 4963;
    int pinInput = 0;

    //intitalizing every index with values sans the users index
    requestArray[0] = true;
    requestArray[1] = true;
    requestArray[2] = true;
    requestArray[3] = false;
    requestArray[4] = false;
    requestArray[5] = true;
    requestArray[6] = false;
    requestArray[7] = false;
    requestArray[8] = true;
    requestArray[9] = false;
    snprintf(nameBox[0], NAMESIZE, "John");
    snprintf(nameBox[1], NAMESIZE, "Alex");
    snprintf(nameBox[2], NAMESIZE, "Zoe");
    snprintf(nameBox[3], NAMESIZE, "Bob");
    snprintf(nameBox[4], NAMESIZE, "Cindy");
    snprintf(nameBox[5], NAMESIZE, "Sera");
    snprintf(nameBox[6], NAMESIZE, "Tom");
    snprintf(nameBox[8], NAMESIZE, "Kat");
    snprintf(nameBox[9], NAMESIZE, "Belle");
    snprintf(requestBox[0], REQUESTSIZE, "1 Burger");
    snprintf(requestBox[1], REQUESTSIZE, "1 Laptop");
    snprintf(requestBox[2], REQUESTSIZE, "20 Hairbrush");
    snprintf(requestBox[3], REQUESTSIZE, "12 Bricks");
    snprintf(requestBox[4], REQUESTSIZE, "10 Books");
    snprintf(requestBox[5], REQUESTSIZE, "7 Cats");
    snprintf(requestBox[6], REQUESTSIZE, "19 Fish");
    snprintf(requestBox[8], REQUESTSIZE, "11 Knives");
    snprintf(requestBox[9], REQUESTSIZE, "5 Golden Bells");
    

    cout << "Enter User ID: ";
    cin >> userIdInput;
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
       userOutput(requestArray, nameBox, requestBox, i);
    }
}

void userInput(bool arrayS[],char arrayN[][NAMESIZE],char arrayR[][REQUESTSIZE], int INDEX)
{
    char decision;
    bool reqCheck = false;

    cout << "Enter your name: ";
    cin.getline(arrayN[INDEX], NAMESIZE);

    cout << "User do you want to make a request? Enter y/n: ";
    decision = cin.get(); //neither cin << or cin.get discard the damn '\n' from the keyboard buffer
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


void userOutput(const bool arrayS[],const char arrayN[][NAMESIZE],const char arrayR[][REQUESTSIZE], int INDEX)
{
    if(arrayS[INDEX] == true)
    {
        cout << INDEX << " ";
        cout << arrayN[INDEX] << " ";
        cout << arrayR[INDEX] << endl;
    }
}



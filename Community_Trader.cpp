#include <iostream>
#include <cctype>

using namespace std;

const int MAXSIZE = 5;
const int NAMESIZE = 5;
const int REQUESTSIZE = 25;


void userInput(bool arrayS[],char arrayR[][REQUESTSIZE], int INDEX);

void userOutput(const bool arrayS[],const char arrayN[][NAMESIZE],const char arrayR[][REQUESTSIZE], int INDEX);

int main()
{
    bool requestArray[MAXSIZE] = {1, 0, 1, 1, 0};
    char nameBox[MAXSIZE][NAMESIZE];
    char requestBox[MAXSIZE][REQUESTSIZE] = {{1, 2, 3, 4, 5}, {}};
    
    snprintf(nameBox[0], NAMESIZE, "John");
    snprintf(nameBox[0], NAMESIZE, "John");

    cout << "Enter User ID: ";
    cout << "Enter Passcode: ";                


    for(int i = 0; i < MAXSIZE; i++ )
    {
       userOutput(requestArray, nameBox, requestBox, i);
    }
}

void userInput(bool arrayS[],char arrayR[][REQUESTSIZE], int INDEX)
{
    char decision;
    bool reqCheck = false;

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
       
       cout << "What request do you want to make?:";
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



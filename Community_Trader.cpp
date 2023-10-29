#include <iostream>
#include <cctype>

using namespace std;

const int MAXSIZE = 5;
const int NAMESIZE = 5;
const int REQUESTSIZE = 25;

bool requestCheck(const bool array[], int INDEX);

void userInput(bool array[], char array2[][REQUESTSIZE], int INDEX);


int main()
{
    bool requestArray[MAXSIZE] = {1, 0, 1, 1, 0};
    char nameBox[MAXSIZE][NAMESIZE];
    char requestBox[MAXSIZE][REQUESTSIZE];

    for(int i = 0; i < MAXSIZE; i++ ) 
    {
        cout << "What is the user's name: ";
        cin.getline(nameBox[i], NAMESIZE, '\n');
        userInput(requestArray, requestBox, i);
        cin.ignore(256, '\n' );        
    }


    for(int i = 0; i < MAXSIZE; i++ )
    {
        cout << requestCheck(requestArray, i) << endl;
    }
}


bool requestCheck(const bool array[], int INDEX)
{
    return array[INDEX];    
}


void userInput(bool array[],char array2[][REQUESTSIZE], int INDEX)
{
    char decision;
    bool reqCheck = false;

    cout << "User do you want to make a request? Enter y/n: ";
    cin >> decision;

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
    if(array[INDEX] == false && reqCheck == true)
    {
       
        cout << "What request do you want to make?:";
        cin.getline(array2[INDEX], REQUESTSIZE);
       
        
    }
    else if(array[INDEX] == true && reqCheck == true)
    {
        cout << "User already has one pending request." << endl;
    }
    else
    {
        cout << "Have a good day!" << endl; 
    }
}



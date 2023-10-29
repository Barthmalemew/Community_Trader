#include <iostream>
#include <cctype>
#include <stdio.h>

using namespace std;

const int MAXSIZE = 5;
const int NAMESIZE = 5;
const int REQUESTSIZE = 25;


void userInput(const bool array1[],char array2[][REQUESTSIZE], int INDEX);

void userOutput(const bool array1[],const char array2[][NAMESIZE],const char array3[][REQUESTSIZE], int INDEX);


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
                
    }


    for(int i = 0; i < MAXSIZE; i++ )
    {
       userOutput(requestArray, nameBox, requestBox, i);
    }
}

void userInput(const bool array1[],char array2[][REQUESTSIZE], int INDEX)
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
    
    snprintf(array2[INDEX],REQUESTSIZE, "L");
    // checks if user has already made a request and if they are currently making a request
    if(array1[INDEX] == false && reqCheck == true)
    {
       
       cout << "What request do you want to make?:";
       cin.getline(array2[INDEX], REQUESTSIZE);
         
    }
    else if(array1[INDEX] == true && reqCheck == true)
    {
        cout << "User already has one pending request." << endl;
    }
    else
    {
        cout << "Have a good day!" << endl; 
    }
}


void userOutput(const bool array1[],const char array2[][NAMESIZE],const char array3[][REQUESTSIZE], int INDEX)
{
    if(array1[INDEX] == true)
    {
        cout << array2[INDEX] << endl;
        cout << array3[INDEX] << endl;
    }
}



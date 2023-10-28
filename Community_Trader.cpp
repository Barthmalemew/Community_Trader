#include <iostream>
#include <cctype>

using namespace std;

const int MAXSIZE = 5;
const int NAMESIZE = 5;

bool requestCheck(const bool array[], int INDEX);

void userInput(bool array[], int INDEX);


int main()
{
    bool requestArray[MAXSIZE];
    char nameBox[MAXSIZE][NAMESIZE];

    for(int i = 0; i < MAXSIZE; i++ ) 
    {
        cout << "What is the user's name: ";
        cin.getline(nameBox[i], NAMESIZE);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        userInput(requestArray, i);
        
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


void userInput(bool array[], int INDEX)
{
    char decision;
    
    cout << "User do you want to make a request? Enter y/n: ";
    cin >> decision;

    decision = tolower(decision);
   
    if(decision == 'y')
    {
        array[INDEX] = true;
    }
    else if(decision == 'n')
    {
        array[INDEX] = false;
    }
}



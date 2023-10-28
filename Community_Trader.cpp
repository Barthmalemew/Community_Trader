#include <iostream>
#include <cctype>

using namespace std;

bool requestCheck(const bool array[], int INDEX);

void userInput(bool array[], int INDEX);

int main()
{
    int size = 5;

    bool requestArray[size];

    for(int i = 0; i < size; i++ )
    {
        userInput(requestArray, i);
    }

    for(int i = 0; i < size; i++ )
    {
        cout << requestCheck(requestArray, i) << endl;
    }
}

bool requestCheck(const bool array[], int INDEX)
{
    return array[INDEX];    
}

//this function is going to ask the user if they want to make a request, see if they are avaliable to make a request(as in they have not already made one) let them make a request if they are avaliable, get their request and then change their request status
void userInput(bool array[], int INDEX)
{
    char decision;
    
    cout << "User do you want to make a request? Enter y/n: " << "\n";
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

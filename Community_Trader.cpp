#include <iostream>

using namespace std;

bool requestCheck(const bool array[], int INDEX);

int main()
{
    int size = 25;

    bool requestArray[size];

    for(int i = 0; i < size; i++ )
    {
        requestArray[i] = 1;
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


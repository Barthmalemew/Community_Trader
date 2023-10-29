#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "mainwindow.h"
#include <QApplication>
#include "requestlist.h"
#include "ui_requestlist.h"

using namespace std;

const int MAXSIZE = 10;
const int NAMESIZE = 11;
const int REQUESTSIZE = 25;

requestList::requestList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::requestList)
{
    ui->setupUi(this);

    for(int i = 0; i < 10; i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(nameBox[i])));
    }
}

requestList::~requestList()
{
    delete ui;
}

void userInput(bool arrayS[],char arrayN[][NAMESIZE],char arrayR[][REQUESTSIZE], int INDEX);

void userOutput(const bool arrayS[],const char arrayN[][NAMESIZE],const char arrayR[][REQUESTSIZE], int INDEX, int uId);

void userGive(bool arrayS[], const char arrayN[][NAMESIZE], const char arrayR[][REQUESTSIZE], int ID);

void randInnit(bool arrayS[]);

void randInnit(char arrayN[][NAMESIZE]);

void randInnit(char arrayR[][REQUESTSIZE]);


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    bool requestArray[MAXSIZE];
    char nameBox[MAXSIZE][NAMESIZE];
    char requestBox[MAXSIZE][REQUESTSIZE];

    srand(time(0));

    int userId = 7;
    int userIdInput = 0;
    int pin = 4963;
    int pinInput = 0;

    //intitalizing every index with values sans the users index // We have to shorten this
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
    snprintf(requestBox[2], REQUESTSIZE, "20 Hairbrushs");
    snprintf(requestBox[3], REQUESTSIZE, "12 Bricks");
    snprintf(requestBox[4], REQUESTSIZE, "10 Books");
    snprintf(requestBox[5], REQUESTSIZE, "7 Cats");
    snprintf(requestBox[6], REQUESTSIZE, "19 Fish");
    snprintf(requestBox[8], REQUESTSIZE, "11 Knives");
    snprintf(requestBox[9], REQUESTSIZE, "5 Golden Bells");


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
        cout << INDEX << " ";
        cout << arrayN[INDEX] << " ";
        cout << arrayR[INDEX] << endl;
    }
}

void userGive(bool arrayS[], const char arrayN[][NAMESIZE], const char arrayR[][REQUESTSIZE], int uId)
{


    char decision = ' ';
    int targetIndex = 0;
    int rId = 0; //index of the person the user is fulfilling the request of

    do
    {
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
                reciveGive = bool(rand() % 1);
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

void randInnit(bool arrayS[])
{

}

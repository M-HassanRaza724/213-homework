#include<iostream>
using namespace std;

void checkSpeed(int speed)
{
    if (speed <= 100)
    {
        cout<<"Perfect! You're going good.";
    }
    if (speed > 100)
    {
        cout<<"Halt... YOU WILL BE CHALLENGED!!!";
    }
}

main()
{
    system("cls");

    int v;
    cout<<"Speed: ";
    cin>>v;

    checkSpeed(v);
}
#include<iostream>
using namespace std;

void Reverse(string boolean)
{
    if(boolean == "true")
    {
        cout<<"false";
    }
    if(boolean == "false")
    {
        cout<<"true";
    }
}

main()
{
    system("cls");

    string boolean;
    cout<<"Enter 'true' or 'false': ";
    cin>>boolean;

    Reverse(boolean);
}
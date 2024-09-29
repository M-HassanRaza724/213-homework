#include<iostream>
using namespace std;

void IsEqual(int n1,int n2)
{
    if(n1 == n2)
    {
        cout<<"True";
    }
    if(n1 != n2)
    {
        cout<<"False";
    }
}

main()
{
    system("cls");

    int no1, no2;
    cout<<"Enter the first number: ";
    cin>>no1;
    cout<<"Enter the second number: ";
    cin>>no2;

    IsEqual(no1, no2);
}
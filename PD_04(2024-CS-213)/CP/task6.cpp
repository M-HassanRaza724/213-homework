#include<iostream>
using namespace std;

void longestTime(int h, int m)
{
    int h_in_m = h*60;
    
    if(h_in_m > m)
    {
        cout<<h<<" hours.";
    }
    if(h_in_m < m)
    {
        cout<<m<<" minutes.";
    }
    if(h_in_m == m)
    {
        cout<<h<<" hours and "<<m<<" minutes both have equal time duration.";
    }
}

int main()
{
    system("cls");

    int hours, mins;
    cout<<"Enter the number of hours: ";
    cin>>hours;
    cout<<"Enter the number of minutes: ";
    cin>>mins;

    longestTime(hours, mins);
}

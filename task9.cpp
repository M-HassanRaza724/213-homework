# include<iostream>
using namespace std;

void tpChecker(int people, int tp)
{
float totalSheets = tp*500;
int sheetsRequired=people*57;
int days=(totalSheets/sheetsRequired);
if(days>13)
{
cout<<"your TP will last "<<days<<" days, no need to panic!";
}
if(days<14)
{
cout<<"your TP will only last "<<days<<" days, buy more!";
}
}

main()
{
int tp, people;
cout<<"Number of people in household: ";
cin>>people;
cout<<"Number of rolls of TP: ";
cin>>tp;
tpChecker(people,tp);
}
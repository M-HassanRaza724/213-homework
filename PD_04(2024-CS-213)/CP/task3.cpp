#include<iostream>
using namespace std;

void priceCalculator(string name, int price)
{
    if (name == "Pakistan")
    {
        cout<<"Final ticket price after discount: $"<<price - (price/20);
    }
    if (name == "Ireland")
    {
        cout<<"Final ticket price after discount: $"<<price - (price/10);
    }
    if (name == "India")
    {
        cout<<"Final ticket price after discount: $"<<price - (price/5);
    }
    if (name == "England")
    {
        cout<<"Final ticket price after discount: $"<<price - (price/100)*30;
    }
    if (name == "Canada")
    {
        cout<<"Final ticket price after discount: $"<<price - (price/100)*45;
    }
}

main()
{
    system("cls");

    string name;
    int price;
    
    cout<<"Enter country,s name: ";
    cin>>name;
    cout<<"Enter the ticket price in dollars: $";
    cin>>price;

    priceCalculator(name, price);
}
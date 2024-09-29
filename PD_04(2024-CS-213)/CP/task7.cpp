#include<iostream>
using namespace std;

void flowerShop(int redRose, int whiteRose, int tulip)
{
    float price = (redRose*2.00)+(whiteRose*4.1)+(tulip*2.50);

    if (price<=200)
    {
        cout<<"Original price: $"<<price<<endl<<"No discount applied.";
    }
    if (price>200)
    {
        float discount = price/5;
        cout<<"Original price: $"<<price<<endl;
        cout<<"Price after discount: $"<<price-discount;

    }
}

int main()
{
    system("cls");

    int red, white, tulip;

    cout<<"Red Rose: ";
    cin>>red;
    cout<<"White Rose: ";
    cin>>white;
    cout<<"Tulip: ";
    cin>>tulip;

    flowerShop(red, white, tulip);
}

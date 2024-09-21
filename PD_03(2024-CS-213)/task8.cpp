# include<iostream>
using namespace std;

int main()
{
   float veg_rate;
   float fruit_rate;
   int veg_kg;
   int fruit_kg;

   cout<<"Enter vegetable price per kilogram (in coins): ";
   cin>>veg_rate;

   cout<<"Enter fruit price per kilogram (in coins): ";
   cin>>fruit_rate;

   cout<<"Enter total kilograms of vegetables: ";
   cin>>veg_kg;

   cout<<"Enter total kilograms of fruits: ";
   cin>>fruit_kg;

// 1 Rs == 1.94 coins

   float earning_Rs = ((veg_kg*veg_rate)+(fruit_kg*fruit_rate))/1.94;
   cout<<"Total earning in Rupees (Rps):"<<earning_Rs;

   return 0;
}

# include <iostream>
using namespace std;

float calculateFruitPrice(string fruit, string dayOfWeek, double quantity);

int main(int argc, char const *argv[])
{
    string fruit, day;
    double quantity,price;

    cout<<"Enter the fruit name: ";
    cin>>fruit;
    cout<<"Enter the day of the week (e.g. Monday, Sunday): ";
    cin>>day;
    cout<<"Enter the quantity: ";
    cin>>quantity;

    price = calculateFruitPrice(fruit, day, quantity);
    cout<<price;
    return 0;
}

float calculateFruitPrice(string fruit, string dayOfWeek, double quantity){

    if(fruit == "banana" || fruit == "apple" || fruit == "orange" || fruit == "grapefruit" || fruit == "kiwi" || fruit == "pineapple" || fruit == "grapes" || dayOfWeek == "monday"|| dayOfWeek == "Tuesday"|| dayOfWeek == "Wednesday"|| dayOfWeek == "Thursday"|| dayOfWeek == "Friday"|| dayOfWeek == "Sunday"|| dayOfWeek == "Saturday"){
        if(dayOfWeek == "Sunday" && dayOfWeek == "Saturday"){
            if (fruit == "banana")
                return quantity*2.70;
            if (fruit == "apple")
                return quantity*1.25;
            if (fruit == "orange")
                return quantity*0.90;
            if (fruit == "grapefruit")
                return quantity*1.60;
            if (fruit == "kiwi")
                return quantity*3.00;
            if (fruit == "pineapple")
                return quantity*5.60;
            if (fruit == "grapes")
                return quantity*4.20;
        }else{
            if (fruit == "banana")
                return quantity*2.50;
            if (fruit == "apple")
                return quantity*1.20;
            if (fruit == "orange")
                return quantity*0.85;
            if (fruit == "grapefruit")
                return quantity*1.45;
            if (fruit == "kiwi")
                return quantity*2.70;
            if (fruit == "pineapple")
                return quantity*5.50;
            if (fruit == "grapes")
                return quantity*3.85;

        }
    }else{
        cout<<"error";
    }
}

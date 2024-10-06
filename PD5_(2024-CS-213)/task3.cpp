# include <iostream>
# include <iomanip>
using namespace std;

float taxCalculator(char,float);

int main()
{
    char type;
    float price;

    cout<<"Enter the vehicle type code (M, E, S, V, T): ";
    cin>>type;
    cout<<"Enter the final price of the vehicle: $";
    cin>>price;

    float final_price = taxCalculator(type,price);
    cout<<"The final price of vehicle of type "<<type<<" after adding the tax is "<< fixed << setw(3) <<final_price;

    return 0;
}

float taxCalculator(char type,float price){
    float tax_rate;
    if (type == 'M'){
        tax_rate = 6;
    }
    else if (type == 'E'){
        tax_rate = 8;
    }
    else if (type == 'S'){
        tax_rate = 10;
    }
    else if (type == 'V'){
        tax_rate = 12;
    }
    else if (type == 'T'){
        tax_rate = 15;
    }
    else{
        cout<<"you have entered the wrong type";
    }

    float tax_amount = (price*tax_rate)/100;
    float final_price = price + tax_amount;

    return final_price;
}

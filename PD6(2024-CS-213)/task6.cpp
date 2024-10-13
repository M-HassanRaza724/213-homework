# include <iostream>
using namespace std; 

string calculateHotelPrices(string month, int numberOfStays);
int main()
{
    string month,answer;
    int days;
    cout<<"Enter the month: (May,June,July,August,September,October): ";
    cin>>month;
    cout<<"Enter the number of stays: ";
    cin>>days;

    answer = calculateHotelPrices(month,days);
    cout<<answer;

    return 0;
}

string calculateHotelPrices(string month, int numberOfStays){
    float Apartment,studio;
    if(month == "May" || month == "October"){
        Apartment = numberOfStays*65;
        studio = numberOfStays*50;
    }
    else if(month == "June" || month == "September"){
        Apartment = numberOfStays*68.70;
        studio = numberOfStays*75.20;
    }
    else if(month == "July" || month == "August"){
        Apartment = numberOfStays*77;
        studio = numberOfStays*76;
    }

    if(numberOfStays>14){
        if(month == "May" || month == "October"){
            studio = studio-(studio*0.3);
        }
        else if(month == "June" || month == "September"){
            studio = studio-(studio*5);
        }
        Apartment = Apartment-(Apartment/10);
    }
    else if(numberOfStays>7 && month == "May" || month == "October"){
        studio = studio-(studio/20);
    }

    return "Apartment: "+to_string(Apartment)+"\nStudio: "+to_string(studio);
}
    



# include <iostream>
using namespace std;

float cellularBill(char,char,unsigned int);
string serviceType(char);

int main(int argc, char const *argv[])
{
    char serviceCode, time = 'd';
    unsigned int minutes;
    float amount;
    cout<<"Enter the service code (R/r for Regular, P/p for premium): ";
    cin>>serviceCode;
    if(serviceCode=='p' || serviceCode=='P'){
        cout<<"Enter time of call (D/d for day, N/n for night): ";
        cin>>time;
    }
    cout<<"Enter the number of minutes used: ";
    cin>>minutes;

    cout<<"Service Type: "<<serviceType(serviceCode)<<endl;
    cout<<"total minutes Used: "<<minutes<<" minutes"<<endl;
    amount = cellularBill(serviceCode,time,minutes);
    cout<<"Amount Due: $"<<amount;

    return 0;
}

string serviceType(char code){
    if(code == 'p' || code == 'P')
        return "Premium";
    else
        return "Regular";
}

float cellularBill(char code,char time,unsigned int minute){

    float amount =0.0;
    if(code == 'p' || code == 'P'){
        if ((time == 'd' || time == 'D' && minute<=75) || (time == 'n' || time == 'N' && minute<=100))
            amount = 25;
        else if(time == 'd' || time == 'D' && minute>75)
            amount = 25+((minute - 75)*0.05);
        else
        amount = 25+((minute - 100)*0.05);
    }
    else if(code == 'r' || code == 'R' && minute>50){
        amount = 10+((minute - 50)*0.20);
    }
    else if(code == 'r' || code == 'R' && minute<=50){
        amount = 10;
    }else{
        cout<<"Wrong Service code.";
    }
    return amount;
}



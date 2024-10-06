# include <iostream>
using namespace std;

string projectTimeCalculation(int,int,int);

int main()
{
    int n_hours,workers,days;
    
    cout<<"Enter the needed hours: ";
    cin>>n_hours;
    cout<<"Enter the days that the firm has: ";
    cin>>days;
    cout<<"Enter the number of all workers: ";
    cin>>workers;

    string R = projectTimeCalculation(n_hours,days,workers);
    cout<<R; 

    return 0;
}


string projectTimeCalculation(int nHours ,int days, int workers){

    int hours = workers*days*9;

    if(hours>nHours){
        return "Yes! "+to_string(hours-nHours)+" hours left.";
    }
    if(hours<nHours){
        return "Not enough time! "+to_string(nHours-hours)+" hours needed.";
    }
}
# include <iostream>
using namespace std;

string Hospital(int);
int dailyPatient(int);


main(){
    int days;
    string report;
    cout<<"Enter the number of days you visited Hospital: ";
    cin>>days;

    report = Hospital(days);
    cout<<report;
    return 0;
}


string Hospital(int hDays){

    int doctor = 7,patients = 0,treated = 0,untreated = 0, checked = 0;

    for (int i = 1; i <= hDays; i++)
    {
        if((i%3 == 0) && (untreated>treated)){
            doctor++;
        }
        patients = dailyPatient(i);
        checked = doctor - patients;
        if(checked >= 0){
            treated = treated + patients;
        }else{
            treated = treated + doctor;
            untreated =  untreated + (-checked);
        }
    }
    return "Treated: "+to_string(treated)+"\nUntreated: "+to_string(untreated);
}

int dailyPatient(int day){
    int patient;
    cout<<"Number of patient who visited Hospital at  Day "<<day<<" :";
    cin>>patient;
    return patient;
}